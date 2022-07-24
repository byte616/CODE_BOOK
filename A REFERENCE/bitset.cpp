// constructing bitsets
#include <iostream>       // std::cout
#include <string>         // std::string
#include <bitset>         // std::bitset
using namespace std;


int main ()
{
	bitset<16> foo;
	bitset<16> bar (0xfa2);
	bitset<16> baz (std::string("0101111001"));

	cout << "foo: " << foo << '\n';
	cout << "bar: " << bar << '\n';
	cout << "baz: " << baz << '\n';
	cout<<foo[0]<<'\n';			//找 foo 從右邊數來的第 0 個 bit
	cout<<foo.count()<<'\n';	//計算有幾個1
	cout<<foo.size()<<'\n';		//計算有幾個bit
	
	std::cout << (foo^=bar) << '\n';       // 1010 (XOR,assign)
	std::cout << (foo&=bar) << '\n';       // 0010 (AND,assign)
	std::cout << (foo|=bar) << '\n';       // 0011 (OR,assign)
	
	std::cout << (foo<<=2) << '\n';        // 1100 (SHL,assign)
	std::cout << (foo>>=1) << '\n';        // 0110 (SHR,assign)
	
	std::cout << (~bar) << '\n';           // 1100 (NOT)
	std::cout << (bar<<1) << '\n';         // 0110 (SHL)
	std::cout << (bar>>1) << '\n';         // 0001 (SHR)

	std::cout << (foo==bar) << '\n';       // false (0110==0011)
	std::cout << (foo!=bar) << '\n';       // true  (0110!=0011)

	std::cout << (foo&bar) << '\n';        // 0010
	std::cout << (foo|bar) << '\n';        // 0111
	std::cout << (foo^bar) << '\n';        // 0101

	return 0;
}


