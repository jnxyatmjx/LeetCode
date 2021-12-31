- ### **Why the need for so many tiers**

> 1. **Single responsibility principle** simply means giving only one responsibility to a component and letting it execute it perfectly, be it saving data, running the application logic or ensuring the delivery of the messages throughout the system. This approach gives us a lot of flexibility and makes management easier. 
> 2. **Separation of concerns** kind of means the same thing, be concerned about your work only and stop worrying about the rest of the stuff. Keeping the components separate makes them reusable. 



- ### What is REST
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




- ### Key Characteristics of Distributed Systems
> 1. **Scalability**
> > - *Horizontal*: add more servers. scale by adding more servers into pool of resources.  水平增加机器
> > - *Vertical*: add more resources to the same server.  scale by adding more power (CPU, RAM, Storage, etc.) to an existing server.  提高单机性能
> 2. **Reliability**.keeps delivering its services even when one or several of its software or hardware components fail
> 2. **Availability**.is the time a system remains operational to perform its required function in a specific period.
> 2. **Efficiency**.
> > - *response time (or latency) that denotes the delay to obtain the first item*
> > - *the throughput (or bandwidth) which denotes the number of items delivered in a given time unit (e.g., a second)*
> 5. **Manageability**.how easy it is to operate and maintain




##Cache
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