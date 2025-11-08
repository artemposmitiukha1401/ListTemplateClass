#include <iostream>

template <class ElementType>
struct Element
{
	ElementType data;
	Element* next;
};

template <class ElementType>
class List
{
	Element<ElementType>* head;
	Element<ElementType>* tail;
	int count;

public:
	List();
	~List();
	void Add(ElementType data);
	void Del();
	void DelAll();
	void Print() const;
	int GetCount() const;
	void Insert(ElementType new_node, int position);
	void RemoveAt(int position);
	int Find(ElementType value);
};
template <class ElementType>
List<ElementType>::List()
{
	head = tail = nullptr;
	count = 0;
}

template <class ElementType>
List<ElementType>::~List()
{
	DelAll();
}

template <class ElementType>
int List<ElementType>::GetCount() const { return count; }

template<class ElementType>
void List<ElementType>::Insert(ElementType new_node, const int position) {
	try {
		if (position < 0 || position > count) throw std::out_of_range("Position out of range");

		Element<ElementType>* previous_element = head;
		Element<ElementType>* current_element = new Element<ElementType>();
		current_element->data = new_node;
		current_element->next = nullptr;

		if (position == 0) {
			current_element->next = head;
			head = current_element;
			if (tail == nullptr) tail = current_element;
			count++;
			return;
		}

		int currentPosition = 0;
		while (currentPosition < position - 1) {
			previous_element = previous_element->next;
			currentPosition++;
		}

		current_element->next = previous_element->next;
		previous_element->next = current_element;

		if (current_element->next == nullptr) {
			tail = current_element;
		}

		count++;
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}

}

template<class ElementType>
void List<ElementType>::RemoveAt(int position) {
	try {
		if (position < 0 || position >= count) throw std::out_of_range("Position out of range");

		Element<ElementType>* target_element = nullptr;
		Element<ElementType>* previous_element = head;

		if (position == 0) {
			target_element = head;
			head = head->next;
			delete target_element;
			if (head == nullptr) tail = nullptr;
			count--;
			return;
		}

		int currentPosition = 0;
		while (currentPosition < position - 1) {
			previous_element = previous_element->next;
			currentPosition++;
		}

		target_element = previous_element->next;
		previous_element->next = target_element->next;
		if (target_element == tail) tail = previous_element;

		delete target_element;
		count--;
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}

}

template<class ElementType>
int List<ElementType>::Find(ElementType value) {
	Element<ElementType>* current_element = head;

	int current_element_index = 0;
	while (current_element != nullptr) {
		if (current_element->data == value) return current_element_index;
		current_element = current_element->next;


		++current_element_index;
	}
	return -1;
}

template <class ElementType>
void List<ElementType>::Add(ElementType data)
{
	Element<ElementType>* temp = new Element<ElementType>;

	temp->data = data;
	temp->next = nullptr;
	if (head != nullptr) {
		tail->next = temp;
		tail = temp;
	}

	else
		head = tail = temp;
	count++;

}
template <class ElementType>
void List<ElementType>::Del() {
	if (head == nullptr) return;

	Element<ElementType>* temp = head;
	head = head->next;
	delete temp;
}

template <class ElementType>
void List<ElementType>::DelAll()
{
	if (head == nullptr) return;

	while (head != nullptr)
		Del();
}
template <class ElementType>
void List<ElementType>::Print() const {
	Element<ElementType>* temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n\n";
}

int main()
{
	// Продвинутый уровень
	//   1. Преобразовать односвязный список в шаблонный класс (узел)
	//   2. Добавить в класс "Односвязный список" следующие функции:
	//   вставка элемента в заданную позицию,
	//   удаление элемента по заданной позиции,
	//   поиск заданного элемента (функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи).

	List<std::string> list;
	list.Add("Hello");
	list.Add("World");
	list.Add("Film");
	list.Print();
	list.Insert("dfs", 3);
	// list.RemoveAt(4);
	list.Print();
	std::cout << list.Find("Hello");


}

