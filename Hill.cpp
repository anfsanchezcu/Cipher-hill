#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int getInversMod(int detA){
  int r= 0;
  for (int i = 1; i < 1000; i++)
  {
    if((detA*i)%26 == 1){
      r=i;
      break;
    }
  }
  return r;
}

string checkText(string line){
  line.erase(remove(line.begin(), line.end(), ' '), line.end());
  line.erase(remove(line.begin(), line.end(), ' '), line.end());
  if(line.length()%2 !=0)line = line+'x';
  return line;
}
vector<int> getInverse(vector<int> v){
  vector<int> result;
  int detA = v[0]*v[3] - v[1]*v[2];
  if(detA==0) return result;

  int mcd = gcd(detA,26);
  if(mcd != 1) return result;

  result.resize(4);
  int invMod = getInversMod(detA);
  
  result[0]=(invMod * v[3])%26; 
  result[1]=(invMod * -v[1])%26; 
  result[2]=(invMod * -v[2])%26; 
  result[3]=(invMod * v[0])%26; 

}

vector<int> multipliMatrix(vector<int> a, vector<int> b){
  vector<int> result(2);
  result[0] = ((a[0] * b[0]) + (a[1] * b[2]));
  result[1] = ((a[0] * b[1]) + (a[1] * b[3]));

  while(result[0]<0)result[0]+=26;
  while(result[1]<0)result[1]+=26;
  result[0] = result[0]%26;
  result[1] = result[1]%26;
  /* cout << result[0] << " " << result[1] <<endl; */
  return result;
}

string cipher(string str, vector <int> v){
  string result ="";
  

}

string decipher(string str, vector <int> v){
  string result ="";
  vector<int> aux;
  for (int i = 0; i < str.length(); i=i+2)
  {
    int a = str[i]-97;
    int b = str[i+1]-97;
    aux= multipliMatrix({a,b},v);
  
    result += (char)(aux[0]+97);
    result += (char)(aux[1]+97);
  }
  cout << result;
  

}

int main(){
  int option; cin >> option;
  cin >> ws;
  string line, result; getline(cin, line);
  int a,b,c,d; cin >> a>>b>>c>>d;
  vector<int> v ={a,b,c,d}; 
  vector<int> v_1 = getInverse(v);
  
  if(v_1.size()!=4){
    cout << "La matriz ingresada no tiene inversa";
    return 0;
  } 
  line = checkText(line);

  if(option == 0) decipher(line, v);
  else decipher(line,v_1);
}