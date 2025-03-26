class Singleton {
    private:
        // 私有构造函数和析构函数
        Singleton() {}
        ~Singleton() {}
        
        // 禁止拷贝和赋值
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        
        // 禁止移动语义
        Singleton(Singleton&&) = delete;
        Singleton& operator=(Singleton&&) = delete;
    
    public:
        static Singleton& getInstance() {
            // 局部静态变量
            static Singleton instance;
            return instance;
        }
        
        // 单例的业务方法
        void someMethod() {
            // 实现代码
        }
    };


class Singleton {
private:
    Singleton() {}
    ~Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance();
};

Q_GLOBAL_STATIC(Singleton, instance)

Singleton& Singleton::getInstance() {
    return *instance;
}