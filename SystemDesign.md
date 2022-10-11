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


### Redis Persistence
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



### TCP Finite State Machine

>- ![](http://www.tcpipguide.com/free/diagrams/tcpfsm.png)
>- <img src="https://coolshell.cn/wp-content/uploads/2014/05/tcp_open_close.jpg" style="zoom:60%;" />
>- 从TIME_WAIT状态到CLOSED状态，有一个超时设置是 2*MSL（[RFC793](https://tools.ietf.org/html/rfc793)）为什么要这有TIME_WAIT？为什么不直接给转成CLOSED状态呢？主要有两个原因：
>>- 1）TIME_WAIT确保有足够的时间让对端收到ACK，如果被动关闭的那方没有收到ACK就会触发被动端重发FIN，一来一去正好2个MSL。
>>- 2）防止旧链接的迷走segment，影响新连接(新旧链接相同四元组)。
>- 如果两边同时断连接，那两边就都会就进入到CLOSING状态，然后到达TIME_WAIT状态。下图是双方同时断连接的示意图。
><img src="http://www.tcpipguide.com/free/diagrams/tcpclosesimul.png" style="zoom:100%"/>

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


* #### CAP

>- **Consistency ( C ):** All users see the same data at the same time.
>- **Availability ( A ):** System continues to function even with node failures.
>- **Partition tolerance ( P ):** System continues to function even if the communication fails between nodes.
* #### Data Partitioning
The act of distributing data across a set of nodes is called data partitioning. 
>- **Consistent Hash**: only a small set of keys move when servers are added or removed.***Caveats$-\infty$*** *this scheme can result in non-uniform data and load distribution*. However solves these issues with the help of Virtual nodes.

* #### Rate limiter
**Rate limiter is used to control the rate of traffic sent by a client or a service**. Include *Token bucket*,*Leaking bucket*,*Fixed window counter*,*Sliding window log*, *Sliding window counter*.
>- Sliding Windows with Redis backend. (使用Sorted Set配合zadd，zremrankbyscore，zcard)实现全局限流器。Local rate limiting can be used in conjunction with global rate limiting to reduce load on the global rate limit service. Thus, the rate limit is applied in two stages. The initial coarse grained limiting is performed by the token bucket limit before a fine grained global limit finishes the job.可以配合本地限流器吸收绝大部分流量以保护全局限流器。所以限流器可以用两步实现。在细颗粒度的全局限流器完成工作之前，初始的粗颗粒度的限制由令牌桶执行。