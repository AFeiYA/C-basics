
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <ctype.h>

using namespace std;
//简单的统计文本中,单词出现的次数.
//we're  it's等会简单的移除标点输出were its.
//使用中午标点会出错。
struct Word
{
    string word;
    int times;
};
struct SortByCounts
{
    bool operator()(const Word & w1, const Word & w2)
    {
        if(w1.times!= w2.times)
            return w1.times>w2.times;
        else
            return w1.word<w2.word;
    }
};

int main()
{
	ifstream file;
	file.open("garden.txt");
	string word, finalWord;
    map<string, int> wm;//words map
    set<Word, SortByCounts> wdSt;
	while (file >> word)
	{
		//cout << word << endl;
		remove_copy_if(word.begin(), word.end(), back_inserter(finalWord), ::ispunct);
		//cout << finalWord << endl;
        ++wm[finalWord];//查找finalWord,如果没有添加元素，如果有统计次数+1;
		finalWord.clear();
	}
	file.close();

    map<string, int>::iterator i;
    for(i=wm.begin();i!=wm.end(); ++i)
    {
        //cout<<i->first<<"\t:\t"<<i->second<<endl;
        Word temp;
        temp.word = i->first;
        temp.times = i->second;
        wdSt.insert(temp);
    }

    set<Word,SortByCounts>::iterator j;
    for(j=wdSt.begin();j!=wdSt.end();++j)
    {
        cout<<j->word<<"\t:\t"<<j->times<<endl;
    }
	return 0;
}
