//using two pointer approach
string reverseWord(string str){

    //Your code here
    int n = str.length();
    int i = 0;
    int j = n -1;
    while (i < j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}
