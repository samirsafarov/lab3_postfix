#define MemSize   30

class TStack 
{
	int *pMem;
	int Size;
	int Top;
public:
	TStack();
	TStack(int n);
	TStack(const TStack &s);
	~TStack();

	bool IsEmpty(void) const;
	bool IsFull(void) const;

	void  Put(const int Val);
	int Peek(void) const;
	int Push(void);

	void SetSize(int n);
};