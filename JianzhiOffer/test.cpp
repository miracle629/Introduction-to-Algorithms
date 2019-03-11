#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

//class CMyString
//{
//public:
//	CMyString(char* pData = NULL);
//	CMyString(const CMyString& str);
//	~CMyString(void);
//private:
//	char* m_pData;
//};
//
//CMyString& CMyString::operator =(const CMyString &str)
//{
//	if (this != &str)
//	{
//		CMyString strTemp(str);
//		char * pTemp = strTemp.m_pData;
//		m_pData = pTemp;
//	}
//	return *this;
//}

//bool FindNum(int* matrix, int row, int col, int num)
//{
//	bool flag = false;
//	int right = col - 1, top = 0;
//	while (top < row && right >= 0)
//	{
//		while (num < matrix[top*col + right])
//			--right;
//		while (num > matrix[top*col + right])
//			++top;
//		if (num == matrix[top*col + right])
//		{
//			flag = true;
//			cout << top << " "<< right << endl;
//			break;
//		}
//	}
//	
//	//while (num > matrix[endLeft])
//	//	++left;
//	return flag;
//}

//void StringTrans(char str[],int length)
//{
//	if (str == NULL || length < 0)
//		return;
//	int cnt = 0;
//	for (int i = 0;i < length;++i)
//	{
//		if (str[i] == ' ')
//			++cnt;
//	}
//	int finalLen = length + 2 * cnt;
//	char* arr = new char[finalLen];
//	//int flag1 = length - 1;
//	if (finalLen == length)
//		return;
//	int flag2 = finalLen - 1;
//	for (int i = length - 1;i >= 0;--i)
//	{
//		if (str[i] == ' ')
//		{
//			arr[flag2--] = '0';
//			arr[flag2--] = '2';
//			arr[flag2--] = '%';
//		}
//		else
//		{
//			arr[flag2--] = str[i];
//		}
//	}
//	for (int i = 0;i < finalLen;++i)
//		cout << arr[i];
//	cout << endl;
//	return;
//}

//------------------------about list------------------------------
struct ListNode
{
	int val;
	ListNode* next;
};

void AddToTail(ListNode** pHead, int value)
{
	ListNode* tmpNode = new ListNode();
	tmpNode->val = value;
	tmpNode->next = NULL;

	if (*pHead == NULL)
	{
		*pHead = tmpNode;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next!=NULL)
		{
			pNode = pNode->next;
		}
		pNode->next = tmpNode;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == NULL || *pHead == NULL)
		return;
	ListNode* deleted = NULL;
	if ((*pHead)->val == value)
	{
		deleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != NULL && pNode->next->val != value)
			pNode = pNode->next;
		if (pNode->next != NULL && pNode->next->val == value)
		{
			deleted = pNode->next;
			pNode->next = pNode->next->next;
		}
		if (pNode->next == NULL)
		{
			delete deleted;
		}

	}
}

void PrintEndToBegin(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->next != NULL)
		{
			PrintEndToBegin(pHead->next);
		}
		cout << pHead->val << endl;
	}
}

void PrintEndToBegin_1(ListNode* pHead)
{
	stack<ListNode*> mystack;
	ListNode* pNode = pHead;
	while (pNode->next != NULL)
	{
		mystack.push(pNode);
		pNode = pNode->next;
	}
	while (!mystack.empty())
	{
		pNode = mystack.top();
		cout << pNode->val << endl;
		mystack.pop();
	}
}

void DeleteNode(ListNode** pHead, ListNode* pToBeDeleted)
{
	if (pHead == NULL || pToBeDeleted == NULL)
		return;
	if (pToBeDeleted->next != NULL)
	{
		ListNode* pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = NULL;
	}
	else if (*pHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		*pHead = NULL;
		pToBeDeleted = NULL;
	}
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->next != pToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

//链表倒数第k个节点
ListNode* FindKthToTail(ListNode* pHead,unsigned int k)
{
	if (pHead == NULL || k == 0)
		return NULL;
	ListNode* aheadNode = pHead;
	ListNode* behindNode = pHead;
	for (unsigned int i = 0;i < k - 1;++i)
	{
		if (aheadNode->next != NULL)
			aheadNode = aheadNode->next;
		else
			return NULL;
	}
	while (aheadNode->next != NULL)
	{
		aheadNode = aheadNode->next;
		behindNode = behindNode->next;
	}
	return behindNode;
}

ListNode* FindMidNode(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;	
	if (pHead->next == NULL)
		return pHead;
	ListNode* _2StepNode = pHead;
	ListNode* _1StepNode = pHead;
	while (_2StepNode->next != NULL)
	{
		_2StepNode = _2StepNode->next;
		_1StepNode = _1StepNode->next;
		if (_2StepNode->next != NULL)
			_2StepNode = _2StepNode->next;
		else
			break;	
	}
	return _1StepNode;
}

bool IsCircleList(ListNode* pHead)
{
	bool res = false;
	return res;
}

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	ListNode* lastFrontNode = NULL;
	ListNode* pNode = pHead;
	ListNode* pFront = NULL;
	while (pNode!= NULL)
	{
		ListNode* pNext = pNode->next;
		if (pNext == NULL)
		{
			lastFrontNode = pNode;
		}
		pNode->next = pFront;
		pFront = pNode;
		pNode = pNext;
	}
	return lastFrontNode;
}

//-----------------------merge 2 ordered list--------------
ListNode* MergeTwoOrderedList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pNode = NULL;
	if (pHead1->val < pHead2->val)
	{
		pNode = pHead1;
		pNode->next = MergeTwoOrderedList(pHead1->next, pHead2);
	}
	else
	{
		pNode = pHead2;
		pNode->next = MergeTwoOrderedList(pHead1, pHead2->next);
	}
	return pNode;
}

//---------------------------class list------------------
class ClassNode
{
private:
	int cData;
	ClassNode* cNext;
public:
	ClassNode(int data)
	{
		this->cData = data;
	}
};

//class NodeLink
//{
//	class ClassNode::ClassNode nHead;
//	class ClassNode::ClassNode nCurrent;
//};

//------------------------about tree----------------------
struct BinTreeNode
{
	char val;
	BinTreeNode* left;
	BinTreeNode* right;
};

void InorderTreeWalk(BinTreeNode *x)
{
	if (x)
	{
		InorderTreeWalk(x->left);
		cout << x->val << endl;
		InorderTreeWalk(x->right);
	}
}

void PreorderTreeWalk(BinTreeNode *x)
{
	if (x)
	{
		cout << x->val << endl;
		InorderTreeWalk(x->left);
		InorderTreeWalk(x->right);
	}
}

void PostorderTreeWalk(BinTreeNode *x)
{
	if (x)
	{
		InorderTreeWalk(x->left);
		InorderTreeWalk(x->right);
		cout << x->val << endl;
	}
}


BinTreeNode* CreateTree()
{
	BinTreeNode *x;
	char ch;
	cin >> ch;
	//cout << ch << endl;
	if (ch == '#') 
		x = NULL;
	else
	{
		x = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		x->val = ch;
		//cout << "ok" << endl;
		x->left = CreateTree();
		x->right = CreateTree();
	}
	return x;
}

BinTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	BinTreeNode* root = new BinTreeNode();
	root->val = rootValue;
	root->left = root->right = NULL;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("invalid");
	}

	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
	{
		++rootInorder;
	}
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("invalid");
	int leftLength = rootInorder - startInorder;
	int* leftPrerderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		root->left = ConstructCore(startPreorder + 1, leftPrerderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		root->right = ConstructCore(leftPrerderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

BinTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

//------------------------------subtree---------------------------------------------------
bool DoesTree1HasTree2(BinTreeNode* pRoot1, BinTreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;

	return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
}

bool HasSubTree(BinTreeNode* pRoot1, BinTreeNode* pRoot2)
{
	bool res = false;
	if ((pRoot1 != NULL) && (pRoot2 != NULL))
	{
		if (pRoot1->val == pRoot2->val)
			res = DoesTree1HasTree2(pRoot1, pRoot2);
		if (!res)
			res = HasSubTree(pRoot1->left, pRoot2);
		if (!res)
			res = HasSubTree(pRoot1->right, pRoot2);
	}
	return res;
}

//-------------------------IsMirrorTree---------------
bool IsMirror(BinTreeNode* pRoot1, BinTreeNode* pRoot2)
{
	if ((pRoot1 == NULL) && (pRoot2 == NULL))
		return true;
	if ((pRoot1 == NULL) || (pRoot2 == NULL))
		return false;
	return (pRoot1->val == pRoot2->val) && IsMirror(pRoot1->left, pRoot2->right)
		&& IsMirror(pRoot1->right, pRoot2->left);
}

bool IsMirrorTree(BinTreeNode* pRoot)
{
	if (pRoot == NULL)
		return false;
	if ((pRoot->left == NULL) && (pRoot->right == NULL))
		return true;
	if ((pRoot->left == NULL) || (pRoot->right == NULL))
		return false;
	return IsMirror(pRoot->left, pRoot->right);
}

//----------------------------trans to mirror tree------------------------------
void TransToMirror(BinTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	if ((pRoot->left == NULL) && (pRoot->right == NULL))
		return;
	BinTreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	if (pRoot->left != NULL)
		TransToMirror(pRoot->left);
	if (pRoot->right != NULL)
		TransToMirror(pRoot->right);
}

//----------------------Levelorder Tree Walk---------------------------------
void LevelorderTreeWalk(BinTreeNode* pRoot)
{
	if (pRoot == NULL)
		return;
	queue<BinTreeNode*> myQueue;
	myQueue.push(pRoot);
	while (myQueue.size())
	{
		BinTreeNode* pNode = myQueue.front();
		cout << pNode->val << endl;
		if (pNode->left)
			myQueue.push(pNode->left);
		if (pNode->right)
			myQueue.push(pNode->right);
		myQueue.pop();
	}
}

//-----------------------------is bin serach tree postorder walk--------------
bool VerifySequenceOfBST(int* seq, int front, int end)
{
	if (seq == NULL || front > end)
		return false;
	int rootNum = seq[end];
	int index = front;
	while (seq[index] < rootNum && index < end)
	{
		++index;
	}
	for (int i = index;i < end;++i)
	{
		if (seq[i] < rootNum)
			return false;
	}
	bool left = true;
	if (index > front)
		left = VerifySequenceOfBST(seq, front, index - 1);
	bool right = true;
	if (index < end)
		right = VerifySequenceOfBST(seq, index, end);
	return (left && right);
}

//---------------------sum of a apth in BST------------------------
void FindThePath(BinTreeNode* pRoot,int sumValue,int currentSum,vector<int>& nodePath)
{
	nodePath.push_back(pRoot->val);
	currentSum += pRoot->val;

	if (pRoot->left == NULL && pRoot->right == NULL)
	{
		if (currentSum == sumValue)
		{
			for (unsigned int i = 0;i < nodePath.size();++i)
			{
				cout << nodePath[i] << endl;
			}
		}
	}
	if (pRoot->left != NULL)
		FindThePath(pRoot->left, sumValue, currentSum, nodePath);
	if (pRoot->right != NULL)
		FindThePath(pRoot->right, sumValue, currentSum, nodePath);

	nodePath.pop_back();
	//currentSum -= pRoot->val;
	return;
}

void FindAPathInBST(BinTreeNode* pRoot, int sumValue)
{
	if (pRoot == NULL)
		return;
	vector<int> nodePath;
	int currentSum = 0;
	FindThePath(pRoot, sumValue, currentSum, nodePath);
}

//--------------------------merge sort-------------------------------
void Merge(int* arr, int begin, int mid, int end)
{
	//int* temp = (int*)malloc((end-begin+1)*sizeof(int));
	int* temp = new int[end - begin + 1];
	int i = begin;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= end)
		temp[k++] = arr[j++];
	for (int u = 0;u <k;++u)
		arr[begin+u] = temp[u];
	//free(temp);
	delete[] temp;
}

void MergeSort_Up2Down(int * arr, int begin, int end)
{
	if (arr == NULL || begin >= end)
		return;
	int mid = (begin + end) / 2;
	MergeSort_Up2Down(arr, begin, mid);
	MergeSort_Up2Down(arr, mid + 1, end);

	Merge(arr, begin, mid, end);
}

//---------------------------quick sort------------

int Pattern(int *arr, int p, int r)
{
	int i = p - 1;
	for (int j = p;j < r;++j)
	{
		if (arr[j] <= arr[r])
		{
			++i;
			swap(arr[i], arr[j]);
		}	
	}
	swap(arr[i], arr[r]);
	return i;
}

void QuickSort(int* arr,int p,int r)
{
	if (p < r)
	{
		int q = Pattern(arr, p, r);
		QuickSort(arr, p, q - 1);
		QuickSort(arr, q + 1, r);
	}
}

//---------------------------heap sort-----------------------
void MaxHeap(int* arr, int i, int end)
{
	int largest;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l <= end && arr[l] > arr[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r <= end && arr[r] > arr[i])
	{
		largest = r;
	}
	if (i != largest)
		swap(arr[largest], arr[i]);
	else
		return;
	MaxHeap(arr, largest, end);
}

void BuildHeap(int* arr,int len)
{
	for (int u = len / 2 - 1;u >= 0;--u)
	{
		MaxHeap(arr, u, len-1);
	}
}

void HeapSort(int* arr)
{
	int len = sizeof(arr);
	int sortSize = len - 1;
	BuildHeap(arr, len);
	for (int v = sortSize;v > 0;--v)
	{
		swap(arr[v], arr[0]);
		--sortSize;
		MaxHeap(arr,0,sortSize);	
	}
}

//------------------------insert sort-----------------------
void InsertSort(int* arr)
{
	int len = sizeof(arr);
	int i = 1, j = 0;
	int temp;
	for (;i < len;++i)
	{
		temp = arr[i];
		j = i - 1;
		while (j>=0 && temp > arr[j])
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
}


//-------------------IOU--------------------------------------
//double ComputeIOU(double* point1, double* point2)
//{
//	if (*point1 == NULL || *point2 == NULL)
//	{
//		return 0;
//	}
//	//double x0=point1[0],y0=point1[1],x1=point1[2],y2=
//	//sum_area = area1 + area2;
//	//minright < maxleft || minbottom < maxtop; return 0;
//	//intersect = (minright - maxleft)*(minbottom - maxtop);
//	//iou = intersect / (sum_area - intersect);
//		
//}

//--------------------------swap test----------------------
//void int_swap(int* arr)
//{
//	swap(arr[0], arr[1]);
//}



//int binarySearch(int *arr, int left, int right, int val)
//{
//	int middle = (left + right) / 2;
//	if (val==arr[middle])
//	{
//		return middle;
//	}
//	else if (val > arr[middle])
//	{
//		left = middle + 1;
//		return binarySearch(arr, left, right, val);
//	}
//	else
//	{
//		right = middle - 1;
//		return binarySearch(arr, left, right, val);
//	}
//}
//
//int binarySearch1(int* arr, int left, int right, int val)
//{
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		
//		if (val > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (val < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//}

//-------------------Fibonicci---------------------------
long long Fib(unsigned int n)
{
	int res[2] = { 0,1 };
	if (n < 2)
		return res[n];

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2;i <= n;++i)
	{
		fibN = fibNMinusTwo + fibNMinusOne;
		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}
	return fibN;
}

//---------------------------stack with min----------------
//template <typename T> void StackWithMin<T>::push(const T& value)
//{
//	m_data.push(value);
//	if (m_min.size() == 0 || value < m_min.top())
//		m_min.push(value);
//	else
//		m_min.push(m_min.top());
//}
//
//template <typename T> void StackWithMin<T>::pop()
//{
//	m_data.pop();
//	m_min.pop();
//}
//
//template <typename T> void StackWithMin<T>::min() const
//{
//	assert(m_data.size() > 0 && m_min.size() > 0);
//	return m_min.top();
//}

//----------------------------my stack and my queue--------------------------
//template <typename T> class MyQueue
//{
//public:
//	MyQueue(void);
//	~MyQueue(void)
//	{
//	};
//
//	void ApplendTail(const T& node);
//	T deleteHead();
//
//private:
//	stack<T> stack1;
//	stack<T> stack2;
//};
//
//template <typename T> MyQueue::MyQueue(void)
//{
//	cout << "ok" << endl;
//}
//
//template <typename T> void MyQueue<T>::ApplendTail(const T& element)
//{
//	stack1.push(element);
//}
//
//template <typename T> T MyQueue<T>::deleteHead()
//{
//	if (stack2.size() <= 0)
//	{
//		while (stack1.size > 0)
//		{
//			T& tmp = stack1.top();
//			stack1.pop();
//			stack2.push(tmp);
//		}	
//	}
//	if (stack2.size() == 0)
//		throw new exception("empty");
//	T head = stack2.top();
//	stack2.pop();
//
//	return head;
//}
//
//template <typename T> class MyStack
//{
//public:
//	MyStack(void);
//	~MyStack(void)
//	{
//	};
//
//	void PushTop(const T& node);
//	T PopTop();
//
//private:
//	queue<T> queue1;
//	queue<T> queue2;
//};
//
//template <typename T> MyStack::MyStack(void)
//{
//	cout << "ok" << endl;
//}
//
//template <typename T> void MyStack<T>::PushTop(const T& node)
//{
//	if (!queue1.empty())
//	{
//		queue1.push(node);
//	}
//	if (queue2.empty())
//		queue1.push(node);
//	else
//		queue2.push(node);
//}
//
//
//template <typename T> T MyStack<T>::PopTop()
//{
//
//}

//-----------------------sort ages-----------------------
void SortAges(int* ages, int length)
{
	if (ages == NULL || length <= 0)
		return;
	const int maxOfAges = 99;
	int timesOfAges[maxOfAges+1];

	for (int i = 0;i <= maxOfAges;++i)
		timesOfAges[i] = 0;
	for (int i = 0;i < length;++i)
	{
		int age = ages[i];
		if (age<0 || age >maxOfAges)
			throw new exception("Invalid age");
		++timesOfAges[age];
	}
	int index = 0;
	for (int i = 0;i <= maxOfAges;++i)
	{
		for (int j = 0;j < timesOfAges[i];++j)
		{
			ages[index] = i;
			++index;
		}
	}
}

int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1;i <= index2;++i)
	{
		if (numbers[i] < result)
			result = numbers[i];
	}
	return result;
}

int MinOfTrans(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		throw new exception("error");
	}

		
	int index1 = 0;
	int index2 = length - 1;
	int mid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			mid = index2;
			break;
		}
		mid = (index1 + index2) / 2;

		if (numbers[index1] == numbers[index2] && numbers[mid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);
		if (numbers[mid] >= numbers[index1])
			index1 = mid;
		else if (numbers[mid] <= numbers[index2])
			index2 = mid;

		return numbers[mid];
	}
}

//---------------------------about bit------------------------
int NumberOf1(int n)
{
	int flag = 1;
	int count = 0;
	while (flag)
	{
		if (n & flag)
			++count;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_ano(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1) & n;
	}
	return count;
}

bool Is2PowN(int n)
{
	bool res = false;
	int numOfOne = NumberOf1_ano(n);
	if (numOfOne == 1)
		res = true;
	return res;
}

int HowManyBit(int m, int n)
{
	int XorNum = m^n;
	int num = NumberOf1_ano(XorNum);
	return num;
}

//---------------------my pow fun------------------------
double MyEqual(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

double PowerWithUnsignedExpo(double base, unsigned int absExpo)
{
	double res = 1.0;
	for (unsigned int i = 1;i <= absExpo;++i)
	{
		res *= base;
	}
	return res;
}

double PowerWithUnsignedExpo_1(double base, unsigned int absExpo)
{
	if (absExpo == 0)
		return 1.0;
	if (absExpo == 1)
		return base;

	double res = PowerWithUnsignedExpo_1(base, absExpo >> 1);
	res *= res;
	if ((absExpo & 1) == 1)
		res *= base;

	return res;

}

double MyPower(double base, int expo)
{
	if (MyEqual(base, 0) && expo < 0)
	{
		throw new exception("Invalid Input");
		return 0.0;
	}
	
	unsigned int absExpo = (unsigned int)(expo);
	if (expo < 0)
		absExpo = (unsigned int)(-expo);

	double res = PowerWithUnsignedExpo(base, absExpo);

	if (expo < 0)
		res = 1.0 / res;

	return res;
}

//-----------------------------1 to max of N bit--------------------------------
void Print1ToMax(int* data, int first, int length)
{
	if (first == length-1)
	{
		bool start = false;
		for (int u = 0;u < length;++u)
		{
			if (data[u] != 0)
				start = true;
			if (start == true)
				cout << data[u];
		}		
		cout << endl;
		return;
	}
	
	for (int j = 0;j < 10;++j)
	{
		data[first + 1] = j;
		Print1ToMax(data, first + 1, length);
	}
	
}

void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	int* data = new int[n];
	for (int i = 0;i < 10;++i)
	{
		data[0] = i;
		Print1ToMax(data, 0, n);
	}
	delete[] data;
}

bool IsFun(int n)
{
	return (n & 1) == 0;
}

void Split2Part(int* arr, int length,bool (*func)(int))
{
	if (arr == NULL || length <= 0)
		return;
	int index1 = 0;
	int index2 = length - 1;
	while (index1 < index2)
	{
		while ((index1<index2) && !IsFun(arr[index1]))
		{
			++index1;
		}
		while ((index1<index2) && IsFun(arr[index2]))
		{
			--index2;
		}
		if (index1 < index2)
		{
			swap(arr[index1], arr[index2]);
		}		
	}
}

void ReorderOddEven(int *arr, int length)
{
	Split2Part(arr, length, IsFun);
}

//-----------------print matrix clock order---------------------------------
void PrintMatrix4Step(int** matrix, int cols, int rows, int start)
{
	int endX = cols - 1 - start;
	int endY = rows - 1 - start;
	for (int i = start;i <= endX;++i)
	{
		cout << matrix[start][i] << endl;
	}
	if (endY > start)
	{
		for (int j = start + 1;j <= endY;++j)
		{
			cout << matrix[j][endX] << endl;
		}
	}
	
	if (endY > start && endX > start)
	{
		for (int i = endX - 1;i >= start;--i)
		{
			cout << matrix[endY][i] << endl;
		}
	}

	if (endX > start && endY > start + 1)
	{
		for (int j = endY - 1;j >= start + 1;--j)
		{
			cout << matrix[j][start] << endl;
		}
	}

}

void PrintMatrixClockwisely(int** matrix, int cols,int rows)
{
	if (matrix == NULL || cols <= 0 || rows <= 0)
		return;
	int start = 0;
	while ((cols > start * 2) && (rows > start * 2))
	{
		PrintMatrix4Step(matrix, cols, rows, start);
		++start;
	}
}

//----------------------pop is push order in stack---------------------------
bool IsPopOrder(const int* nPush, const int* nPop, int nLength)
{
	bool res = false;
	if (nPush == NULL || nPop == NULL || nLength <= 0)
		return false;
	int pushIndex = 0;
	int popIndex = 0;
	stack<int> myStack;
	while(popIndex<nLength)
	{
		while (myStack.empty() || myStack.top() != nPop[popIndex])
		{
			if (pushIndex == nLength)
				break;

			myStack.push(nPush[pushIndex]);
			++pushIndex;
		}
		if (myStack.top() != nPop[popIndex])
			break;
		myStack.pop();
		++popIndex;
	}
	if (myStack.empty() && popIndex == nLength)
		res = true;
	return res;
}

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 4,5,3,2,1 };
	int arr3[] = { 4,3,5,1,2 };

	bool res1 = IsPopOrder(arr1, arr2, 5);
	bool res2 = IsPopOrder(arr1, arr3, 5);
	cout << res1 << "," << res2 << endl;

	/*int matrix[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	PrintMatrixClockwisely(matrix,)*/


	/*int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int len = sizeof(arr)/sizeof(int);
	cout << len << endl;
	ReorderOddEven(arr, len);
	for (int i = 0;i < len;++i)
	{
		cout << arr[i] << endl;
	}*/

	/*int N = 2;
	Print1ToMaxOfNDigits(N);*/


	/*BinTreeNode* bTree = NULL;
	cout << "start" << endl;
	bTree = CreateTree();
	cout << "--------------------" << endl;
	PreorderTreeWalk(bTree);
	cout << "--------------------" << endl;
	InorderTreeWalk(bTree);
	cout << "--------------------" << endl;
	PostorderTreeWalk(bTree);
	cout << "--------------------" << endl;*/


	/*int arr[] = {1,2,3};
	int_swap(arr);
	cout << arr[0] << arr[1] << endl;*/

	/*ListNode stu[3];
	ListNode *head, *p;
	stu[0].val = 10;
	stu[1].val = 20;
	stu[2].val = 30;

	head = &stu[0];
	stu[0].next = &stu[1];
	stu[1].next = &stu[2];
	stu[2].next = NULL;

	p = head;
	do {
	cout << p->val;
	p = p->next;
	}while(p!=NULL);*/

	/*char str1[] = "We are happy.";
	int len = sizeof(str1);
	cout << len << endl;
	StringTrans(str1, len);*/

	/*int matr[] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	bool res = FindNum(matr,4,4,5);
	cout << res << endl;*/



	/*int a = 3;
	int* arr = new int[a];

	for (int u = 0;u < a;++u)
	{
	cin >> arr[u];
	}
	for (int u = 0;u < a;++u)
	{
	cout << arr[u];
	cout << endl;
	}


	delete[] arr;*/

	/*int n = 3, m = 2;
	int **arr2;
	arr2 = new int *[m];
	for (int i = 0;i < m;++i)
	{
	arr2[i] = new int[n];
	}

	for (int u = 0;u < m;++u)
	{
	for (int v = 0;v < n;++v)
	{
	cin >> arr2[u][v];
	}
	}

	for (int u = 0;u < m;++u)
	{
	for (int v = 0;v < n;++v)
	{
	cout << arr2[u][v];
	cout << endl;
	}
	}
	cout << "1" << endl;
	delete [] arr2;
	cout << "2" << endl;*/
	return 0;
}