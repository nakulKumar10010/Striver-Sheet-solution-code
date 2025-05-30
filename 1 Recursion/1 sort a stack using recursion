/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void sortedInsert(stack<int> &s, int num){
    //if empty or num is greater than top just insert the element
    if(s.empty() || (!s.empty() && num > s.top())){
        s.push(num);
        return;
    }
    
    
    //if num is smaller remove above element and
    int x = s.top();
    s.pop();
    ////call the funtion to get the num inserted in sorted order
    sortedInsert(s, num);
    
    //now insert x in sorted stack
    s.push(x);
}

void SortedStack ::sort() {
    // is empty??
    if(s.empty()){
        return;
    }
    
    //top lement ko save
    int num = s.top();
    s.pop();
    sort();
    
    //sorted order m insert
    sortedInsert(s, num);
}
