#include <iostream>


using namespace std;


long long int pow(long long int a,long long int b){
	long long int res=1;
	for(int i=0;i<b;i++) res=res*a;
		return res;
}

unsigned long long int gcd(unsigned long int a,unsigned long int b){  //
	while(a%b !=0){
		unsigned long long int c=a%b;
		a=b;
		b=c;
	}
	return b;
}

unsigned long long int mod_add(unsigned long long int a,unsigned long long int b,unsigned long long int n){
	return (a%n+b%n)%n;
}


unsigned long long int mod_mult(unsigned long long int a,unsigned long long int b,unsigned long long int n){
	return (a%n*b%n)%n;
}

unsigned long long int mod_inverse(unsigned long long int a,unsigned long long int m){
	
	unsigned long long int k=0;
	while(true){
		k++;
		if(a*k%m==1) break;
		
	}
	return k;
}


unsigned long long int mod_exp(unsigned long long int b,unsigned long long int e,unsigned long long int m){
	unsigned long long int result=1;
	for(unsigned long long int i=0;e !=0;i++){
		if(e%2 ==1){
			result=(result*b)%m;

		}
		b=b*b;
		e=e/2;
		b=b%m;
	}
	return result;
}

long long int disc_log(long long int a,long long int b,long long int c){
		long long int x=0;
		long long int term=1;	
	while(term!=b){
		term=term*a;
		term=term%c;
		x++;
	}
return x;

	
}

unsigned long long int encrypt_key(unsigned long long int key){
	unsigned long long int p=3457,q=382801;

	unsigned long long int n=p*q; 
	unsigned long long int e=8609;
	
	unsigned long long int c=mod_exp(key,e,n);
	return c;
}
unsigned long long int decrypt_key(unsigned long long int c){
	
	unsigned long long int p=3457,q=382801;
	unsigned long long int n=p*q; unsigned long long int $=(p-1)*(q-1);
	unsigned long long int e=8609;unsigned long long int d=mod_inverse(e,$);

	unsigned long long int k=mod_exp(c,d,n);
	return k;
}


int main(){
	cout<<"!!! WELCOME to our project !!!"<<endl<<endl;
	cout<<"This Project contains the following functions"<<endl;
	cout<<"1) Modulo addition"<<endl<<"2) Modulo multiplication"<<endl<<"3) Modulo exponention"<<endl;
	cout<<"4) Descrete Logarithm "<<endl;
	cout<<"5) GCD & inverse modulo n"<<endl<<"6) RSA encryption & Decryption"<<endl<<"Press 0 to exit "<<endl<<endl;
	cout<<"Note-this project doesn't contain big integer class "<<endl;

	cout<<"Enter the Sr. no of the function you want to use."<<endl;
	long long int n1;
	cin>>n1;
	while(true){
		if(n1==0) { 
			cout<<"Thanks for using our Project "<<endl;
			break;
		}

	else if(n1==1){
		cout<<"For modulo addition ,enter the two numbers a, b and the modulo n,respectively "<<endl;
		unsigned long long int a,b,n;
		cin>>a>>b>>n;
		cout<<"Your result is "<<mod_add(a,b,n)<<endl<<endl;
	}

	else if(n1==2){
		cout<<"For modulo multiplication ,enter the two numbers a, b and the modulo n,respectively "<<endl;
		unsigned long long int a,b,n;
		cin>>a>>b>>n;
		cout<<"Your result is "<<mod_mult(a,b,n)<<endl<<endl;
	}

	else if(n1==3){
		cout<<"For modulo exponentiation ,enter the two numbers a, b and the modulo n,respectively "<<endl;
		unsigned long long int a,b,n;
		cin>>a>>b>>n;
		cout<<"Your result is "<<mod_exp(a,b,n)<<endl<<endl;
	}

	else if(n1==4){
		cout<<"To find x in the expression a^x = b mod n , enter a,b and n respectively "<<endl;
		unsigned long long int a,b,n;
		cin>>a>>b>>n;

		cout<<"Your result is "<<disc_log(a,b,n)<<endl<<endl;
	}

	else if(n1==5){
		cout<<"For GCD and Inverse ,enter two numbers a, n respectively "<<endl;
		unsigned long long int a,n;
		cin>>a>>n;
		cout<<"GCD of a & n is "<<gcd(a,n)<<endl;
		if(gcd(a,n)!=1) cout<<"Inverse doesn't exist "<<endl;
		else cout<<"Inverse of "<<a<< " wrt " <<n <<" is "<<mod_inverse(a,n)<<endl<<endl;
	}

	else if(n1==6){
		cout<<"For RSA encryption ,enter any number you want to encrypt eg- pin code,phone number /n(Please enter atmost 9 digit number)"<<endl;
		unsigned long long int a;
		cin>>a;
		cout<<"Taking the public keys as e=8609 & n=1323343057 /n then the encrypted ciphertext is "<<encrypt_key(a)<<endl;
		cout<<"For RSA decryption ,enter the ciphertext you want to decrypt(public keys e=8609 & n=1323343057) "<<endl;
		unsigned long long int c;cin>>c;
		cout<<"The decrypted message is "<<decrypt_key(c)<<" for your ciphertext"<<endl<<endl;

	}
	else cout<<n1<<" is invalid Sr. no. "<<endl<<endl;
	cout<<"Enter the Sr. no of the function you want to use."<<endl;
	cin>>n1;

	}
}