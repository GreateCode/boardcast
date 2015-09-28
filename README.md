# boardcast
轻量的c++消息驱动框架 ， 只依赖c++11

目标是把服务器里面各个逻辑模块隔离开来，让服务器代码实现高内聚低耦合。

-observer 
  观察者类 用于管理注册的侦听对象和分发消息
  
-facade
  外观类 全局访问的唯一接口
  
-ilistener
  侦听接口类，所有的逻辑模块都拥有这个类的接口，做为模块唯一的对外接口类。
