class Node{
  public:
    Node(int value);
    ~Node();
    void setValue(int x);
    int getValue();
    Node * getNext();
    void setNext(Node * n);
    int printValue();

  private:
    int value;
    Node * next;
};