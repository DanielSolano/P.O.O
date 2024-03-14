class Pilas
{
    struct nodo
    {
        int dato = 0;
        struct nodo *prev = nullptr;
    };
    struct nodo *top = nullptr;

public:
    void push(int dato);
    int pop(void);
    void clear(void);
    bool IsEmpty(){return (top == nullptr);}
    int peek();
    ~Pilas();

};