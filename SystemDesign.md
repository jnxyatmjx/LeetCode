### **Why the need for so many tiers**

> 1. **Single responsibility principle** simply means giving only one responsibility to a component and letting it execute it perfectly, be it saving data, running the application logic or ensuring the delivery of the messages throughout the system. This approach gives us a lot of flexibility and makes management easier. 
> 2. **Separation of concerns** kind of means the same thing, be concerned about your work only and stop worrying about the rest of the stuff. Keeping the components separate makes them reusable. 



### What is REST
> 1. **REST** stands for **Representational State Transfer**. It’s a software architectural style for implementing web services. Web services implemented using the REST architectural style are known as the **RESTful Web services**.
>
> 1. REST为**表现层状态转换**，是一种构建网络服务的软件架构风格，符合这种风格的网络服务就叫**RESTful**网络服务
>
>    
- ### Steps of solve System Design Programs
> 1. **Requirements clarification**s. 明确需求
> 2. **Back-of-the-envelope estimation**.It is always a good idea to estimate the scale of the system we’re going to design. 粗略评估
> 3. **System interface definition**.Define what APIs are expected from the system. 定义系统接口
> 4. **Defining data model**.The ata model will clarify how data will flow between different system components. Later, it will guide for data partitioning and management.(e.g. storage, transportation, encryption)定义数据模型
> 4. **High-level design**.Design the core components of our system.We should identify enough components that are needed to solve the actual problem from end to end.
> 4. **Detailed design**.There is no single answer,the only important thing is to consider ***Tradeoffs  between different options while keeping system constraints in mind***.细节设计
> 4. **Identifying and resolving bottlenecks**.找到并解决系统瓶颈
> > -  Is there any single point of failure in our system.
> > -  How are we monitoring the performance of our service.




### Key Characteristics of Distributed Systems
> 1. **Scalability**
> > - *Horizontal*: add more servers. scale by adding more servers into pool of resources.  水平增加机器
> > - *Vertical*: add more resources to the same server.  scale by adding more power (CPU, RAM, Storage, etc.) to an existing server.  提高单机性能
> 2. **Reliability**.keeps delivering its services even when one or several of its software or hardware components fail
> 2. **Availability**.is the time a system remains operational to perform its required function in a specific period.
> 2. **Efficiency**.
> > - *response time (or latency) that denotes the delay to obtain the first item*
> > - *the throughput (or bandwidth) which denotes the number of items delivered in a given time unit (e.g., a second)*
> 5. **Manageability**.how easy it is to operate and maintain



### Cache

___
- ### Keep the cache coherent with the source of truth缓存与库一致性
> 1. **Write-through cache:** Under this scheme, data is written into the cache and the corresponding database simultaneously. 缓存与库***同时写***
>	+ we will have complete data consistency between the cache and the storage.
>	+ this scheme has the disadvantage of higher latency for write operations.
> 2. **Write-around cache:** This technique is similar to write-through cache, but data is written directly to permanent storage, bypassing the cache.只写库***不写缓存***
> 	+ This can reduce the cache being flooded with write operations that will not subsequently be re-read
> 	+ disadvantage that a read request for recently written data will create a “cache miss” and must be read from slower back-end storage and experience higher latency.
> 3. **Write-back cache:** Data is written to cache alone, and completion is immediately confirmed to the client.The write to the permanent storage is done after specified intervals or under certain conditions.只写缓存***不写库***
> 	+ low-latency and high-throughput for write-intensive applications.
> 	+  risk of data loss  because the only copy of the written data is in the cache.
- ### Cache eviction policies缓存淘汰策略
> 1. **First In First Out (FIFO)**: The cache evicts the first block accessed first without any regard to how often or how many times it was accessed before.
> 2. **Last In First Out (LIFO)**: The cache evicts the block accessed most recently first without any regard to how often or how many times it was accessed before.
> 3. **Least Recently Used (LRU)**: Discards the least recently used items first.
> 4. **Most Recently Used (MRU)**: Discards, in contrast to LRU, the most recently used items first.
> 5. **Least Frequently Used (LFU)**: Counts how often an item is needed. Those that are used least often are discarded first.
> 6. **Random Replacement (RR)**: Randomly selects a candidate item and discards it to make space when necessary.





### Socket Error

> - ***man errno***
> -  **EAGAIN**    Resource temporarily unavailable (may be the same value as EWOULDBLOCK) (this error can be ignore e.g. ZeroMQ).
> -  **EWOULDBLOCK**     Operation would block (may be same value as EAGAIN) (POSIX.1-2001).



### ZeroMQ
> - A high-performance asynchronous messaging library,It provides a message queue.
> - ZeroMQ supports *common messaging patterns* (**pub/sub, request/reply, client/server** and others) over a variety of transports (TCP, in-process, inter-process, multicast, WebSocket and more), making inter-process messaging as simple as inter-thread messaging. 
>	- The inter-process transport passes messages between local processes using a system-dependent IPC mechanism. 
>	- The in-process transport passes messages via memory directly between threads sharing a single ØMQ *context*.
> - A ZeroMQ message is a discrete unit of data passed between applications or components of the same application.


### Redis
> - 序号发生器 INCR key
> - 滑动窗口 API限流（使用Sorted Set配合zadd，zremrankbyscore，zcard)


#### Redis Persistence
1. `AOF(Append Only File) `通过保存Redis的**写命令**来保存数据库状态。具体通过`命令追加`、`文件写入同步`三个步骤实现持久化
> - **命令追加**: 每个写命令都会以协议格式追加到aof_buf缓冲区。
>
> - **文件写入同步**:Redis服务进程就是一个事件循环，处理文件事件、时间事件等。在写的文件事件循环结束前，都会调用flushAOF函数来将aof_buf中的数据写入和保存到`AOF`文件中。同时根据`appedfsync`选项对写入命令进行实际文件同步落盘操作。
>
>> -  appendfsync: ***always(可能丢失一个事件内的的所有写命令)***、everysec(会丢失一秒钟数据)、no(文件同步操作由操作系统决定，Redis重启会丢失数据)
>> - AOF有文件重写功能以压缩日益膨胀的aof文件体积
> - AOF保存写命令过程，数据恢复速度较慢
2. `RDB(Redis Data Binary)`使用键值对的压缩二进制文件保存数据库状态。
> - 通过SAVE和BGSAVE两种命令创建RDB文件，前者创建时会阻塞工作进程，而后者则另起一个子进程做创建工作不会阻塞Redis工作进程。
> - Redis周期性操作函数serverCron，定期检查是否满足RDB操作条件(save 600 3. 600秒内至少操作了3次修改)。如果满足则进行RDB相关操作。类似定时器操作***所以较容易丢失数据***
> - RDB紧凑的单文件保存数据快照，易于传输且数据恢复速度快
>

3. In theory, **for asynchronous replication**, there is no guarantee to prevent data loss. 理论上，异步数据复制无法保证数据不丢失
> -  However, this is an extremely low probability scenario as described above.但是可以极大减少出现的概率



* ### OOP
>- Difference between a `Reference` variable and a `Pointer` in C++?
>A pointer stores the address of the variable whereas a reference variable is just an alias for that variable.



### Design Pattern
> - **Factory Method Pattern** is defined as providing an interface for object creation but delegating the actual instantiation of objects to subclasses. 为对象的创建提供一个接口，但将对象实例化委托给子类。
> - **Abstract factory pattern** is defined as defining an interface to create families of related or dependent objects without specifying their concrete classes. 定义一个接口来创建相关或依赖对象的家族，而不用指定它们的具体类。
> - **Observer Pattern** is defined as a one to many dependency between objects so that when one object changes state all the dependents are notified.定义了一对多的类关系。当一个subject状态发生变化时，所有observe能够感知到。
> - **State Pattern** is defined as allowing an object to alter behavior when its internal state changes so that it appears to change its class. 允许对象在其内部状态发生变化时，改变其行为。看上去就像改变了自身所属类一样。
> - **Prototype** is a creational design pattern that lets you copy existing objects without making your code dependent on their classes.是一种创建模式。允许在不依赖其他类的前提下复制此类对象。



### TCP Finite State Machine

>- ![](http://www.tcpipguide.com/free/diagrams/tcpfsm.png)
>- <img src="https://coolshell.cn/wp-content/uploads/2014/05/tcp_open_close.jpg" style="zoom:60%;" />
>- 从TIME_WAIT状态到CLOSED状态，有一个超时设置是 2*MSL（[RFC793](https://tools.ietf.org/html/rfc793)）为什么要这有TIME_WAIT？为什么不直接给转成CLOSED状态呢？主要有两个原因：
>>- 1）TIME_WAIT确保有足够的时间让对端收到ACK，能够安全正确的关闭双全工TCP连接。如果被动关闭的那方没有收到ACK就会触发被动端重发FIN，一来一去正好2个MSL。
>>- 2）防止旧链接的**迷走segment**(e.g. **迷走**就是由于路由协议的问题，TCP分组被路由器A转发给路由器B，随后又被路由器B转发给路由器A)，影响新连接(新旧链接相同四元组)。
>- 如果两边同时断连接，那两边就都会就进入到CLOSING状态，然后到达TIME_WAIT状态。下图是双方同时断连接的示意图。
><img src="http://www.tcpipguide.com/free/diagrams/tcpclosesimul.png" style="zoom:100%"/>
------
### HTTPS
How does HTTPS work?

Hypertext Transfer Protocol Secure (HTTPS) is an extension of the Hypertext Transfer Protocol (HTTP.) HTTPS transmits encrypted data using Transport Layer Security (TLS.) If the data is hijacked online, all the hijacker gets is binary code.<img src="D:\EastMoney\LeetCode\pictures\https.jpg" style="zoom:47%;" />

> Step 1 - The client (browser) and the server **establish a TCP connection**.创建TCP连接
>
> Step 2 - The client sends a “**client hello**” to the server. The message contains a set of necessary encryption algorithms and the latest TLS version it can support. The server responds with a “**server hello**” so the browser knows whether it can support the algorithms and TLS version.The **server then sends the SSL certificate to the client**. The certificate contains the public key, host name, expiry dates, etc. The client validates the certificate.客户端与服务段相互发送hello，用以确定加密算法和TLS版本。确定好后服务段发送证书给客户端，证书中包含公钥、过期时间和域名。
>
> Step 3 - After validating the SSL certificate, the **client generates a session key** and encrypts it using the public key. The server receives the encrypted session key and decrypts it with the private key.客户端校验完证书正确后生成session key，并用证书加密后发给服务端，服务端用私钥解密得到session key。
>
> Step 4 - Now that both the client and the server hold the same session key (**symmetric encryption**), the encrypted data is transmitted in a secure bi-directional channel.客户端和服务端通过session key对数据进行对称加密。
>
> Why does HTTPS switch to symmetric encryption during data transmission? There are two main reasons:
>>1. Security: The asymmetric encryption goes only one way. This means that if the server tries to send the encrypted data back to the client, anyone can decrypt the data using the public key.
>>2. Server resources: The asymmetric encryption adds quite a lot of mathematical overhead. It is not suitable for data transmissions in long sessions.

### MySQL


#### InnoDB Cluster

>- MySQL InnoDB Cluster provides a complete high availability solution for MySQL. Each MySQL server instance in an InnoDB Cluster runs MySQL Group Replication, which provides the mechanism to replicate data within an InnoDB Cluster, with built-in failover.
>- [MySQL Router](https://dev.mysql.com/doc/mysql-router/8.0/en/) can automatically configure itself based on the cluster you deploy, connecting client applications transparently to the server instances.
>- In the default Single-Primary mode, an InnoDB Cluster has a single Read-Write server instance - the Primary. Multiple secondary server instances are replicas of the primary. If the primary fails, a secondary is automatically promoted to the role of primary. 
>- follow diagram show an overview of how the technologies work together:![](https://dev.mysql.com/doc/mysql-shell/8.0/en/images/innodb_cluster_overview.png)

#### InnoDB 主从复制原理
>- MySQL Master 将数据变更写入二进制日志( binary log, 其中记录叫做二进制日志事件binary log events，可以通过 show binlog events 进行查看)
>- MySQL Slave 向Master发送dump协议，Master收到dump请求后向Slave推送bin log。
>- MySQL Slave 将binary log events 拷贝到它的中继日志(Relay log)。
>- MySQL Slave 重放 relay log 中事件，将数据变更反映它自己的数据。





### Distributed System


#### CAP
>- **Consistency ( C ):** All users see the same data at the same time.
>- **Availability ( A ):** System continues to function even with node failures.
>- **Partition tolerance ( P ):** System continues to function even if the communication fails between nodes.
#### Data Partitioning
The act of distributing data across a set of nodes is called data partitioning. 
>- **Consistent Hash**: is a special kind of hashing such that when a hash table is re-sized and consistent hashing is used, only $k/n$ keys need to be remapped on average, where $k$ is the number of keys, and $n$ is the number of slots(Each **slot** is represented by **a server** in a distributed system or cluster).一致哈希是一个hash环，key映射到环的某个位置后，由指定的node(也就是服务器)负责。当node增加或删除后
>> - only a small set of keys move when servers are added or removed.
>> - *This scheme can result in non-uniform data and load distribution*.First, it is impossible to keep the same size of partitions on the ring for all servers considering a server can be added or removed.Second, it is possible to have a non-uniform key distribution on the ring. However solves these issues with the help of ***Virtual Nodes***.

#### Rate limiter
**Rate limiter is used to control the rate of traffic sent by a client or a service**. Include *Token bucket*,*Leaking bucket*,*Fixed window counter*,*Sliding window log*, *Sliding window counter*.

>- Sliding Windows with Redis backend. (使用Sorted Set配合zadd，zremrankbyscore，zcard)实现全局限流器。Local rate limiting can be used in conjunction with global rate limiting to reduce load on the global rate limit service. Thus, the rate limit is applied in two stages. The initial coarse grained limiting is performed by the token bucket limit before a fine grained global limit finishes the job.可以配合本地限流器吸收绝大部分流量以保护全局限流器。所以限流器可以用两步实现。在细颗粒度的全局限流器完成工作之前，初始的粗颗粒度的限制由令牌桶执行。

#### RPC
**RPC** (Remote Procedure Call) is called “𝐫𝐞𝐦𝐨𝐭𝐞” because it enables communications between remote services when services are deployed to different servers. From the user’s point of view, it acts like a local function call.让远程服务器上的不同服务间进行通讯，从用户角度看就像调用本地函数一样。

  <img src="D:\EastMoney\LeetCode\pictures\Fg-cdXRVEAArIQf.jpg" style="zoom:43%;" />
#### Distribute Lock
> - **Redis Single Instance Lock**
> >   Set-if-Not-Exists to obtain a lock, atomic Delete-if-Value-Matches to release a lock. **As an efficiency optimization, not for correctness**.For example, a good use case is maintaining request counters per IP address (for rate limiting purposes) and sets of distinct IP addresses per user ID (for abuse detection).上锁时 如果没有就设置key_name，其值为每个用户特定随机值uid并设置超时。放琐时用户能匹配uid就可以安全删除，防止用户释放了他人锁。
> >
> >   ```lua
> >   --acquire the lock
> >   SET key_name client_random_value NX PX 3000
> >   --release the lock
> >   if redis.call("get",KEYS[1]) == ARGV[1] then
> >       return redis.call("del",KEYS[1])
> >   else
> >       return 0
> >   end
> >   ```
> - **Redis Redlock Algorithm**
> > 1. It gets the current time in milliseconds. 客户端获取当前时间戳。
> > 2. It tries to acquire the lock in all the $N$ instances **Sequentially**, using the same key name and random value in all the instances. During step 2, when setting the lock in each instance, the client uses a timeout which is small compared to the total lock auto-release time in order to acquire it. For example if the auto-release time is 10 seconds, the timeout could be in the ~ 5-50 milliseconds range. This prevents the client from remaining blocked for a long time trying to talk with a Redis node which is down: if an instance is not available, we should try to talk with the next instance ASAP.
> >   客户端 使用相同key和随机value，在N个实例中***顺序***获取锁。如果锁有效时间为10秒，则令获取锁的超时时间为50毫秒，以保证在某个实例节点不可达时客户端能尽快的轮询下一个节点实例。
> > 3. The client computes how much time elapsed in order to acquire the lock, by subtracting from the current time the timestamp obtained in step 1. If and only if the client was able to acquire the lock in the majority of the instances (at least 3), and the total time elapsed to acquire the lock is less than lock validity time, the lock is considered to be acquired. 
> >   客户端通过公式计算加锁的消耗时间 $ T当前时间戳 - 步骤1的时间戳$。当且仅当客户端获得了大部分锁($N/2+1$)且$T$小于锁有效时间，则认为客户端加锁成功。
> > 4. If the lock was acquired, its validity time is considered to be the initial validity time minus the time elapsed, as computed in step 3. 
> >   如果加锁成功，则此锁的有效时间为原始锁有效时间(10秒)减去步骤3中的加锁耗时$T$。
> > 5. If the client failed to acquire the lock for some reason (either it was not able to lock N/2+1 instances or the validity time is negative), it will try to unlock all the instances (even the instances it believed it was not able to lock).
> >   如果加锁失败，则会主动释放所有节点锁。
> - **Zookeeper** is a distributed key-value store and is used for coordination and storing configurations. It is highly optimized for reads. 基于redis的分布式锁有两个问题
> - 有fencing tocken错误，如下图
> <img src="D:\EastMoney\LeetCode\pictures\fencingtoken.JPG" alt="10%" style="zoom: 86%;" />
> 
>- 基于分布式系统时间假设情况。即分布式系统中每个节点的本地时间基本一致增张方向相同，且锁有效期远大于节点间的时间漂移。(NTP与本地时间差距巨大，管理员修改了时间等情况)。
> 
>> 1.创建永久属性znode作为锁节点。
> > 2.用户加锁时在锁节点下创建临时有序znode。
> > 3.用户加锁时如下：
> > 3-1. 在锁节点下创建临时有序子节点。EPHEMERAL_SEQUENTIAL znode
>> 3-2. 查找锁节点的所有子节点并按序号排序。
>> 3-3. 如果序号是最小序号子节点则加锁成功。
>> 3-4. 如果不是最小序号则监听上一个子节点的变动，并等待。防止惊群现象。
>> 4.用户释放琐时，直接删除其创建的临时有序子节点。

####Kafka

Kafka was created at LinkedIn around 2010 to track various events, such as page views, messages from the messaging system, and logs from various services.
A Kafka server is also called a **broker**. Brokers are responsible for reliably storing data provided by the producers and making it available to the consumers.Kafka divides its messages into categories called **Topics**. In simple terms, a **topic** is like a table in a database, and the messages are the rows in that table.As topics can get quite big, they are split into **partitions** of a smaller size for better performance and scalability.Kafka guarantees that **all messages inside a partition are stored in the sequence they came in**. **Ordering** of messages is maintained **at the partition level**, not across the topic.By using **consumer groups**, consumers can be parallelized so that multiple consumers can read from multiple partitions on a topic, allowing a very high message processing throughput. 

A **leader** **is the node responsible for *all* reads and writes** for the given partition. **Every partition** has one Kafka broker **acting as a leader**.To handle single point of failure, Kafka can replicate partitions and distribute them across multiple broker servers called **followers**.

**To handle split-brain** (where we have **multiple active controller brokers**), Kafka uses ‘epoch number,’ which is simply a monotonically increasing number to indicate a server’s generation.**This epoch is included in every request that is sent from the Controller to other brokers**.This way, brokers can easily differentiate the real Controller by simply **trusting the Controller with the highest number**. This epoch number is stored in ZooKeeper.

- How can a producer know that the data is successfully stored at the leader or that the followers are keeping up with the leader？生产者保证数据写入成功的几种方式
> **Async**: Producer sends a message to Kafka and does not wait for acknowledgment from the server. 
> **Committed to Leader**: Producer waits for an acknowledgment from the leader. 
> **Committed to Leader and Quorum**: Producer waits for an acknowledgment from the leader and the quorum.
- What message-delivery guarantees does Kafka provide to consumers? kafka怎样保证消费者消费到数据。
> **At-most-once**: Messages may be lost but are never redelivered.**Consumers** commit message offsets before they process them.消费者先commit offset再处理消息。
> **At-least-once**: Messages are never lost but may be redelivered.**Consumer** can process the message first and then commit the offset. 消费者先处理消息再commit offset。
> **Exactly-once**: Each message is delivered once and only once. Tags every message with a sequence number. In this way, the broker can keep track of the largest number per PID and reject duplicates.
------
Why is Kafka fast?
<img src="D:\EastMoney\LeetCode\pictures\kafaka-zerocopy.jpg" style="zoom: 63%;" />

#### Quorum Consensus 法人共识算法
**Quorum consensus** can guarantee consistency for both read and write operations.The configuration of $W$, $R$ and $N$ is a typical tradeoff between latency and consistency.

>- $N$ = The number of replicas.
>- $W$ = A write quorum of size $W$. For a write operation to be considered as successful, write
operation must be acknowledged from $W$ replicas.
>- $R$ = A read quorum of size $R$. For a read operation to be considered as successful, read
operation must wait for responses from at least $R$ replicas.

####Bloom Filter
**Bloom Filter** how to make a valid choice of parameter.[here](https://hur.st/bloomfilter/)
>- $n$  number of items in the filter.
>- $m$ number of bits in the filter.
>- $k$  number of hash functions.
>- $p$ probability of **False Positives**. fraction between 0 and 1 or a number indicating $1$-in-$p$.