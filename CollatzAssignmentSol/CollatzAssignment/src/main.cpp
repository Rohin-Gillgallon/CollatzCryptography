#include <iostream>
#include <memory>
#include "Collatz.h"
#include "LoginSystem.h"
#include "StrengthAnalysis.h"
#include "Generate.h"
#include "Decryption.h"

using namespace std;

/*std::string encrypt(std::string& word, const std::function<std::string(std::vector<int>)>& toString);

static auto toString = [&](std::vector<int> encword)
{
	std::stringstream hidden;
	for (int i = 0; i < encword.size(); ++i)
	{
		hidden << encword[i];
	}
	std::string encpass = hidden.str();
	return encpass;
};*/

int main()
{
	unique_ptr<Collatz> C = make_unique<Collatz>();
	C->System();

	/*std::string all = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 !\"#$%^&*(){}[];:'@~,<.>//|*-+"};
	std::string sent = {"A friend to all is a friend to none"};
	std::string code = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	for (int i = 0; i < all.size(); i++)
	{
		cout << all[i] << ' ' << encrypt(sent + all[i], toString) << "\n";
	}
	if (encrypt(sent, toString) == code)
		cout << "TRUE!\n";
	else
		cout << "FALSE!\n";*/
	//system("pause");
}