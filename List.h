template <class DataType,class T2>

class Listt {
private:
	class Node {
	public:
		DataType data;
		T2 harga;
		Node* link;
	};

	Node* pHead;
	Node* pCurr;
	int numItem;

public:
	Listt();
	~Listt();
	void AddToFront();
	void DeleteFront();
	void printData(int baris);
	int NumberOfItem();
};

template<class DataType,class T2>
Listt<DataType,T2>::Listt() {
	numItem = 0;
	pHead = 0;
}
template<class DataType, class T2>
Listt<DataType, T2>::~Listt() {}

template<class DataType, class T2>
void Listt<DataType, T2>::AddToFront() {
	DataType item;
	T2 harga;
	Node* pNew = new Node;
	cout << "Enter data Buah : ";
	cin >> item;
	cout << "Enter Harga: ";
	cin >> harga;

	pNew->data = item;
	pNew->harga = harga;
	pNew->link = pHead;
	pHead = pNew;
	numItem++;
}

template<class DataType, class T2>
void Listt<DataType, T2>::printData(int baris) {
	pCurr = pHead;
	system("cls");
	cout << "=========================\n\n";

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (size_t i = 1; pCurr != 0; i++){

	bool selected = (i == baris);
	
	if (selected)
         SetConsoleTextAttribute(hConsole, 0x70);
     else
         SetConsoleTextAttribute(hConsole, 7);

		cout << pCurr->data << "  ";
		cout << pCurr->harga << "\n";
		pCurr = pCurr->link;
	
	}
	SetConsoleTextAttribute(hConsole, 7);

	cout << "\n";
}

template<class DataType, class T2>
int Listt<DataType, T2>::NumberOfItem() {
	return numItem;
}

template<class DataType, class T2>
void Listt<DataType, T2>::DeleteFront() {
	pHead = pHead->link;
	numItem--;
	cout << "First Item Deleted" << endl;
}