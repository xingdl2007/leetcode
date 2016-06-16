#include <string>
#include <iostream>

using namespace std;

#include "longestpalindromicsubstring.cc"

int main()
{
	string s1 = (new Solution())->longestPalindrome("hello");
	cout << s1 << endl;

	string s2 = (new Solution())->longestPalindrome("helleh");
	cout << s2 << endl;

	string s3 = (new Solution())->longestPalindrome("abcdefg");
	cout << s3 << endl;

	string s4 = (new Solution())->longestPalindrome("heliloabccbaefg");
	cout << s4 << endl;

	string s5 = (new Solution())->longestPalindrome("cwziydanrqvsdtvnnqgjnbrvvwxwqojeqgxhwxdoktjktulemwpbeqscbbtbfvkxsrjetfdrovcrdwzfmnnihtgxybuairswfewvpuscocqifuwylhssldpjrawqdrbvkykpaggspbfrulcktpbofchzikhzxhpocgvdbwpewpywsgqbczmamprklaoovcfecwchhmsaqkhvuvvzjblmgvqpqtnlipgqsanvovylpmxlmxvymppdykphhaamtxjnnlsqfwjwhyywgurteaummwhvavxbcpgrfffxrowluqmqjaugryxdmwvyokdcfcvcytxpixbvwrdgzctejdoaavgtezexmvxgrkpnayvfarkyoruofqmpnsqdzojxqrjsnfwsbzjmaoigytygukqlrcqaxazvmytgfghdczvzphfdbnxtklaiqqsotavdmhiaermluafheowcobjqmrkmlzyas");
	cout << s5 << endl;

	string s6 = (new Solution())->longestPalindrome("ccc");
	cout << s6 << endl;

	string s7 = (new Solution())->longestPalindrome("aaaa");
	cout << s7 << endl;

	string s8 = (new Solution())->longestPalindrome("bbbbb");
	cout << s8 << endl;

	string s9 = (new Solution())->longestPalindrome("lqlvciwekzxapmjxyddlaoqhfhwphamsyfwjinkfvciucjhdgwodvmnpkibumexvlsxxumvrznuuyqfavmgwfnsvfbrvqhlvhpxaqehsiwxzlvvtxsnmlilbnmvnxyxitxwoahjricdjdncvartepfpdfndxqoozkfpdmlpvshzzffsspdjzlhmamqooooor");
	cout << s9 << endl;

	string s10 = (new Solution())->longestPalindrome("lplooooor");
	cout << s10 << endl;

	string s11 = (new Solution())->longestPalindrome("jhgtrclvzumufurdemsogfkpzcwgyepdwucnxrsubrxadnenhvjyglxnhowncsubvdtftccomjufwhjupcuuvelblcdnuchuppqpcujernplvmombpdttfjowcujvxknzbwmdedjydxvwykbbamfnsyzcozlixdgoliddoejurusnrcdbqkfdxsoxxzlhgyiprujvvwgqlzredkwahexewlnvqcwfyahjpeiucnhsdhnxtgizgpqphunlgikogmsffexaeftzhblpdxrxgsmeascmqngmwbotycbjmwrngemxpfakrwcdndanouyhnnrygvntrhcuxgvpgjafijlrewfhqrguwhdepwlxvrakyqgstoyruyzohlvvdhvqmzdsnbtlwctetwyrhhktkhhobsojiyuydknvtxmjewvssegrtmshxuvzcbrabntjqulxkjazrsgbpqnrsxqflvbvzywzetrmoydodrrhnhdzlajzvnkrcylkfmsdode");
	cout << s11 << endl;

	return 0;
}
