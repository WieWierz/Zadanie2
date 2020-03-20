#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class pal{
       ifstream plik1;
       ofstream plik2;
       string linia;

	public:
        pal();
        ~pal();
        
    void sprawdzenie();
};
	pal::pal()
	{ 
   	 	plik1.open("wyrazy1.txt");
  		plik2.open("wyrazy2.txt");
	}
	
	bool isPalindrome(string s)
			{
        		int back = s.length()-1;
        		bool palindrome = true;
        		for (int i=0; i<s.length()/2 && palindrome; i++)
                		if (s[i] != s[back--]) 
                        		palindrome = false;
               	return palindrome;
			}
			
		void pal::sprawdzenie()
		{
			if(plik1.good()) 
				plik2<<"["<<endl;
            while(!plik1.eof()) 
                {
                   getline(plik1,linia);
                   
                   	string s(linia), slowo, linia("");
       				stringstream ss(s);
        			while(ss >> slowo)
                	linia += slowo;
                	
  
                   plik2<<"{\"napis\": \""<<linia<<"\", \"wynik\":";
                   if(isPalindrome(linia))
                   {
                   	plik2<<"\"TAK\"},"<<endl;
				   }else
				   {
				   	plik2<<"\"NIE\"},"<<endl;
				   }

				}
				plik2<<"]"<<endl;
								
		}
	pal::~pal()
	{ 
    	plik1.close();
    	plik2.close();
	}
	
int main(int argc, char** argv) {
	
	pal p;
	p.sprawdzenie();
    	
	return 0;
}
