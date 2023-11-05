// Online C++ compiler to run C++ program online
#include <iostream>
#include <iostream>


template <typename T>
class Stac{
  private:
    int mysize;
    T* mydata;
  public:
    Stac() {
        mysize=0;
    }
    ~Stac() {
      delete[] mydata;
    }

    T pop(){
        if(mysize==0){
            std::cout << "Stac is empty" << std::endl;
        }
        else{
            
            T val = mydata[mysize-1];
            mydata[mysize-1] = 0;
            mysize--;
            return val;
        }
        return -1;
    }
    void push(T data) {
        if(mysize==0){
            mydata = new T[mysize++];
            mydata[mysize-1] = data;
        }else{
            mysize++;
        mydata[mysize-1] = data;
        
        }
    }
    T top() {
        if(mysize==0){
            return -1;
        }else{
        return mydata[mysize-1];
        }
    }
    bool empty() {
    return (mysize==0);
    }
    size_t size() {
        return mysize;
    }
};

int main() {
    // Write C++ code here
   
    Stac<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    std::cout << st.top() <<std::endl;
    std::cout << st.pop() << std::endl;
    std::cout << st.top() << std::endl;
    return 0;
}