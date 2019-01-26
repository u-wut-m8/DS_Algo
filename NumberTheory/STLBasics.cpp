#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>

template<typename T>
void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
	std::cout<<"After Swapping : "<<a<<' '<<b<<std::endl;
}

int main(){
	int a = 10, b = 20;
	std::cout<<"Before Swapping : "<<a<<' '<<b<<std::endl;
	swap(a, b);
	float c = 3.17, d = 9.81;
	std::cout<<"Before Swapping : "<<c<<' '<<d<<std::endl;
	swap(c, d);
	
	
	/*String basics
	append(): Inserts additional characters at the end of the string (can also be done using �+� or �+=� operator). Its time complexity is O(N) where N is the size of the new string.
assign(): Assigns new string by replacing the previous value (can also be done using �=� operator).
at(): Returns the character at a particular position (can also be done using �[ ]� operator). Its time complexity is O(1).
begin(): Returns an iterator pointing to the first character. Its time complexity is O(1).
clear(): Erases all the contents of the string and assign an empty string (��) of length zero. Its time complexity is O(1).
compare(): Compares the value of the string with the string passed in the parameter and returns an integer accordingly. Its time complexity is O(N + M) where N is the size of the first string and M is the size of the second string.
copy(): Copies the substring of the string in the string passed as parameter and returns the number of characters copied. Its time complexity is O(N) where N is the size of the copied string.
c_str(): Convert the string into C-style string (null terminated string) and returns the pointer to the C-style string. Its time complexity is O(1).
empty(): Returns a boolean value, true if the string is empty and false if the string is not empty. Its time complexity is O(1).
end(): Returns an iterator pointing to a position which is next to the last character. Its time complexity is O(1).
erase(): Deletes a substring of the string. Its time complexity is O(N) where N is the size of the new string.
find(): Searches the string and returns the first occurrence of the parameter in the string. Its time complexity is O(N) where N is the size of the string.
insert(): Inserts additional characters into the string at a particular position. Its time complexity is O(N) where N is the size of the new string.
length(): Returns the length of the string. Its time complexity is O(1).
replace(): Replaces the particular portion of the string. Its time complexity is O(N) where N is size of the new string.
resize(): Resize the string to the new length which can be less than or greater than the current length. Its time complexity is O(N) where N is the size of the new string.
size(): Returns the length of the string. Its time complexity is O(1).
substr(): Returns a string which is the copy of the substring. Its time complexity is O(N) where N is the size of the substring.*/
	
	std::string s1 = "Hello";
	const char *s2 = s1.c_str();
	std::cout<<s1<<' '<<s2<<std::endl;
	if(s1.compare(s2) == 0)
		std::cout<<"Yes they are equal!"<<std::endl;
	s1.append(" potato...");
	std::cout<<s1<<std::endl;
	
	/*Vector basics
	at(): Returns the reference to the element at a particular position (can also be done using �[ ]� operator). Its time complexity is O(1).
back(): Returns the reference to the last element. Its time complexity is O(1).
begin(): Returns an iterator pointing to the first element of the vector. Its time complexity is O(1).
clear(): Deletes all the elements from the vector and assign an empty vector. Its time complexity is O(N) where N is the size of the vector.
empty(): Returns a boolean value, true if the vector is empty and false if the vector is not empty. Its time complexity is O(1).
end(): Returns an iterator pointing to a position which is next to the last element of the vector. Its time complexity is O(1).
erase(): Deletes a single element or a range of elements. Its time complexity is O(N + M) where N is the number of the elements erased and M is the number of the elements moved.
front(): Returns the reference to the first element. Its time complexity is O(1).
insert(): Inserts new elements into the vector at a particular position. ts time complexity is O(N + M) where N is the number of elements inserted and M is the number of the elements moved .
pop_back(): Removes the last element from the vector. Its time complexity is O(1).
push_back(): Inserts a new element at the end of the vector. Its time complexity is O(1).
resize(): Resizes the vector to the new length which can be less than or greater than the current length. Its time complexity is O(N) where N is the size of the resized vector.
size(): Returns the number of elements in the vector. Its time complexity is O(1).*/

	std::vector<int> v;
	std::vector<int>::iterator it;
	v.push_back(5);
	while(v.back() > 0)
		v.push_back(v.back()-1);
	for(it=v.begin();it!=v.end();it++)
		std::cout<<*it<<' ';
	std::cout<<std::endl;
	for(int i=0;i<v.size();i++)
		std::cout<<v.at(i)<<' ';
	std::cout<<std::endl;
	while(!v.empty()){
		std::cout<<v.back()<<' ';
		v.pop_back();
	}
	std::cout<<std::endl;
	
	/*List basics
	begin( ): It returns an iterator pointing to the first element in list.Its time complexity is O(1). 
end( ): It returns an iterator referring to the theoretical element(doesn�t point to an element) which follows the last element.Its time complexity is O(1). 
empty( ): It returns whether the list is empty or not.It returns 1 if the list is empty otherwise returns 0.Its time complexity is O(1). 
assign( ): It assigns new elements to the list by replacing its current elements and change its size accordingly.It time complexity is O(N).
back( ): It returns reference to the last element in the list.Its time complexity is O(1). 
erase( ): It removes a single element or the range of element from the list.Its time complexity is O(N). 
front( ): It returns reference to the first element in the list.Its time complexity is O(1). 
push_back( ): It adds a new element at the end of the list, after its current last element. Its time complexity is O(1). 
push_front( ): It adds a new element at the beginning of the list, before its current first element. Its time complexity is O(1). 
remove( ): It removes all the elements from the list, which are equal to given element. Its time complexity is O(N). 
pop_back( ): It removes the last element of the list, thus reducing its size by 1. Its time complexity is O(1). 
pop_front( ): It removes the first element of the list, thus reducing its size by 1. Its time complexity is O(1). 
insert( ): It insert new elements in the list before the element on the specified position. Its time complexity is O(N). 
reverse ( ): It reverses the order of elements in the list. Its time complexity is O(N). 
size( ): It returns the number of elements in the list. Its time complexity is O(1).*/

	std::list<int> li;
	std::list<int>::iterator it1;
	li.push_back(4);
	li.push_back(5);
	li.push_front(3);
	li.push_front(5);
	it1 = li.begin();
	li.insert(it1, 1);
	for(it1=li.begin();it1!=li.end();++it1)	
		std::cout<<*it1<<' ';
	std::cout<<std::endl;
	li.reverse();
	for(it1=li.begin();it1!=li.end();it1++)
		std::cout<<*it1<<' ';
	std::cout<<std::endl;
	li.remove(5);
	for(it1=li.begin();it1!=li.end();it1++)
		std::cout<<*it1<<' ';
	std::cout<<std::endl;
	li.pop_back();
	li.pop_front();
	for(it1=li.begin();it1!=li.end();it1++)
		std::cout<<*it1<<' ';
	std::cout<<std::endl;
	
	std::pair<int, char> p1;
	std::pair<int, char> p2(2, 'b');
	p1 = std::make_pair(1, 'c');
	std::cout<<p1.first<<' '<<p1.second<<std::endl
			 <<p2.first<<' '<<p2.second<<std::endl;
	
	/*Set basics
	begin(): Returns an iterator to the first element of the set. Its time complexity is O(1).
clear(): Deletes all the elements in the set and the set will be empty. Its time complexity is O(N) where N is the size of the set.
count(): Returns 1 or 0 if the element is in the set or not respectively. Its time complexity is O(logN) where N is the size of the set.
empty(): Returns true if the set is empty and false if the set has at least one element. Its time complexity is O(1).
end(): Returns an iterator pointing to a position which is next to the last element. Its time complexity is O(1).
erase(): Deletes a particular element or a range of elements from the set. Its time complexity is O(N) where N is the number of element deleted.
find(): Searches for a particular element and returns the iterator pointing to the element if the element is found otherwise it will return the iterator returned by end(). Its time complexity is O(logN) where N is the size of the set.
insert(): insert a new element. Its time complexity is O(logN) where N is the size of the set.
size(): Returns the size of the set or the number of elements in the set. Its time complexity is O(1).*/
	
	std::set<int> t1;
	std::set<int>::iterator it2;
	int arr[] = {3, 5, 2, 1, 5, 4};
	for(int i=0;i<6;i++)
		t1.insert(*(arr+i));
	for(it2=t1.begin();it2!=t1.end();it2++)
		std::cout<<*it2<<' ';
	std::cout<<std::endl;
	std::cout<<*(t1.find(4));
	std::cout<<std::endl;
	
	/*Map basics
	Note: N is the number of elements in map.
Some Member Functions of map:
at( ): Returns a reference to the mapped value of the element identified with key.Its time complexity is O(logN). 
count( ): searches the map for the elements mapped by the given key and returns the number of matches.As map stores each element with unique key, then it will return 1 if match if found otherwise return 0.Its time complexity is O(logN). 
clear( ): clears the map, by removing all the elements from the map and leaving it with its size 0.Its time complexity is O(N). 
begin( ): returns an iterator(explained above) referring to the first element of map.Its time complexity is O(1). 
end( ): returns an iterator referring to the theoretical element(doesn�t point to an element) which follows the last element.Its time complexity is O(1).
empty( ): checks whether the map is empty or not. It doesn�t modify the map.It returns 1 if the map is empty otherwise returns 0.Its time complexity is O(1).
erase( ): removes a single element or the range of element from the map.
find( ): Searches the map for the element with the given key, and returns an iterator to it, if it is present in the map otherwise it returns an iterator to the theoretical element which follows the last element of map.Its time complexity is O(logN). 
insert( ): insert a single element or the range of element in the map.Its time complexity is O(logN), when only element is inserted and O(1) when position is also given.*/
	
	std::map<char, int> mp;
	std::map<char, int> mymap, mymap1;
	std::map<char, int>::iterator it3;
	mp.insert(std::pair<char, int>('a', 2));
	mp.insert(std::pair<char, int>('b', 1));
	mp.insert(std::pair<char, int>('c', 43));
	mymap.insert(mp.begin(), mp.end());
	it3 = mp.find('b');
	std::cout<<it3->first<<' '<<it3->second<<std::endl;
	mymap1['x'] = 21;
	mymap1['y'] = 23;
	mymap.swap(mymap1);
	std::cout<<"mymap after swapping ==>"<<std::endl;
	for(it3=mymap.begin();it3!=mymap.end();it3++)
		std::cout<<it3->first<<' '<<it3->second<<std::endl;
	std::cout<<"mymap1 after swapping ==>"<<std::endl;
	for(it3=mymap1.begin();it3!=mymap1.end();it3++)
		std::cout<<it3->first<<' '<<it3->second<<std::endl;
	mymap1.erase('c');
	for(it3=mymap1.begin();it3!=mymap1.end();it3++)
		std::cout<<it3->first<<' '<<it3->second<<std::endl;
	mymap1.erase(mymap1.begin(), mymap1.end());
	if(mymap1.empty())
		std::cout<<"mymap1 is empty!"<<std::endl;
	std::cout<<"Frequency of 'a' in mp = "<<mp.count('a')<<std::endl;
	
	/*Stack basics
	push( ): Insert element at the top of stack. Its time complexity is O(1). 
pop( ): removes element from top of stack. Its time complexity is O(1). 
top( ): access the top element of stack. Its time complexity is O(1). 
empty( ): checks if the stack is empty or not. Its time complexity is O(1). 
size( ): returns the size of stack. Its time complexity is O(1).*/

	std::stack<int> st;
	for(int i=6;i<=10;i++)
		st.push(i);
	std::cout<<st.size()<<std::endl;
	std::cout<<"Top of stack = "<<st.top()<<std::endl;
	for(int i=0;i<5;i++)
		st.pop();
	if(st.empty())
		std::cout<<"Stack is empty!"<<std::endl;
		
	/*Queue basics
	push( ): inserts an element in queue at one end(rear ). Its time complexity is O(1). 
pop( ): deletes an element from another end if queue(front). Its time complexity is O(1). 
front( ): access the element on the front end of queue. Its time complexity is O(1). 
empty( ): checks if the queue is empty or not. Its time complexity is O(1). 
size( ): returns the size of queue. Its time complexity is O(1).*/

	std::queue<char> q;
	char qu[] = {'a', 'b', 'c', 'd'}, ch;
	for(int i=0;i<4;i++)
		q.push(qu[i]);
	for(int i=0;i<3;i++)
		ch = q.front();
	q.push(ch);
	q.pop();
	while(!q.empty()){
		std::cout<<q.front();
		q.pop();
	}
	std::cout<<std::endl;
	
	/*Priority queue
	empty(): Returns true if the priority queue is empty and false if the priority queue has at least one element. Its time complexity is O(1).
pop(): Removes the largest element from the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
push(): Inserts a new element in the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
size(): Returns the number of element in the priority queue. Its time complexity is O(1).
top(): Returns a reference to the largest element in the priority queue. Its time complexity is O(1).*/

	std::priority_queue<int> pq;
	pq.push(10);
	pq.push(20);
	pq.push(5);
	while(!pq.empty()){
		std::cout<<pq.top()<<' ';
		pq.pop();
	}
	std::cout<<std::endl;

	/*Bitset basics
	As bitset stores the same information in compressed manner the operation on bitset are faster than that of array and vector. We can access each bit of bitset individually with help of array indexing operator [] that is bs[3] shows bit at index 3 of bitset bs just like a simple array. Remember bitset starts its indexing backward that is for 10110, 0 are at 0th and 3rd indices whereas 1 are at 1st 2nd and 4th indices.
We can construct a bitset using integer number as well as binary string via constructors which is shown in below code. The size of bitset is fixed at compile time that is, it can�t be changed at runtime.
The main function defined for bitset class are operator [], count, size, set, reset and many more*/

	std::bitset<32> b1;
	std::bitset<32> b2(20);
	std::bitset<32> b3(std::string("1100"));
	std::cout<<b1<<std::endl
			 <<b2<<std::endl
			 <<b3<<std::endl;
	std::bitset<8> set8;
	set8[1] = 1;
	set8[4] = set8[1];
	int numberOf1 = set8.count();
	std::cout<<"0s = "<<numberOf1<<" 1s = "<<set8.size() - numberOf1<<std::endl;
	if(!b1.any())
		std::cout<<"b1 has no bit set!"<<std::endl;
	if(!b2.none())
		std::cout<<"b2 has some bit set!"<<std::endl;
	std::cout<<set8.set()<<std::endl;
	std::cout<<set8.set(4, 0)<<std::endl;
	std::cout<<set8.set(4)<<std::endl;
	std::cout<<set8.reset(2)<<std::endl;
	std::cout<<set8.reset()<<std::endl;
	std::cout<<set8.flip(2)<<std::endl;
	std::cout<<set8.flip()<<std::endl;
	int num = 100;
	std::cout<<std::bitset<8>(num)<<std::endl;
	std::bitset<4> bset1(9);
    std::bitset<4> bset2(3);
    std::cout<<(bset1 == bset2)<<std::endl;
    std::cout<<(bset1 != bset2)<<std::endl;
    std::cout<<(bset1 ^= bset2)<<std::endl;
    std::cout<<(bset1 &= bset2)<<std::endl;
    std::cout<<(bset1 |= bset2)<<std::endl;
    std::cout<<(bset1 <<= 2)<<std::endl;
    std::cout<<(bset1 >>= 1)<<std::endl;
    std::cout<<(~bset2)<<std::endl;
    std::cout<<(bset1 & bset2)<<std::endl;
    std::cout<<(bset1 | bset2)<<std::endl;
    std::cout<<(bset1 ^ bset2)<<std::endl;

	return 0;
}
