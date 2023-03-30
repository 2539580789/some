class Single{
    private:
        Single();
        static Single *instance;
    public:
        static Single *get();
};