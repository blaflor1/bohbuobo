
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{	LinkedList<string> shopList;
	shopList.insert("eggs");
	shopList.insert("milk");
	shopList.insert("sugar");
	shopList.remove("")
	vector<string> v;
	v.push_back("eggs");
	v.push_back("milk");
	v.push_back("sugar");
	v.pop_back();
	v.push_back("coffee");
	for(vector<string>::iterator iter = v.v.begin(); iter != v.end(); iter++) {
		if(*iter == "coffee") *iter = "Honey";
		
	}
	return 0;
}