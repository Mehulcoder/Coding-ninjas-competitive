/*Hackerrank problem "sam and substring"*/

int substrings(string n) {

long long total_sum = n[0]-'0';
long long last_value = n[0] - '0';

for(int i=1; i<n.length(); i++){
    last_value = ((last_value*10)+((n[i]-'0')*(i+1)))%1000000007;
    total_sum = (total_sum + last_value)%1000000007;
}
return total_sum;
}


