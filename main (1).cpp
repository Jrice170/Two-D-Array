

#include <iostream>
#include <cstdlib>
using namespace std;
//typedef double* D_var;


class TwoD
{
    
    private:
    
    int maxcol;
    int maxRows;
    int usedcol;
    int usedRows;
    
    
    public:
    typedef double* D_var;
    TwoD(); // default constructor
    TwoD(int i, int j); 
    TwoD(const TwoD & Array); /// copy constructor 
    int Maxcol()const{return (maxcol);}
    int Maxrows()const{return (maxRows);}
    int Usedcol()const{return (usedcol);}
    int UsedRows()const{return (usedRows);}
    void addElement(double value);
    bool full(){return ((maxcol == usedcol) && (maxRows == usedRows));}
    D_var *pointer;
    void Display();
    void rand_fill();
    
    /// operator overload
    
    
    
    
};

int main()
{
    
  TwoD h(5,5);
  
  h.rand_fill();
  h.Display();
  TwoD j(h);
  cout<<endl;
  j.Display();
  
}

TwoD::TwoD(int i,int j): maxcol(i),maxRows(j),usedcol(0),usedRows(0)
{
    
     // loop 
        
        pointer = new D_var[maxRows];
        
        for(int i =0;i<maxRows;i++)
        {
            
          pointer[i] = new double[maxcol];
              
              
        }
        
    
}

/// default
TwoD::TwoD():maxcol(5),maxRows(5),usedcol(0),usedRows(0)
{
   
   pointer = new D_var[maxRows];
   
   for(int i = 0; i < maxRows;i++)
   {
       
       pointer[i] = new double[maxcol];
       
   }
     
}


TwoD::TwoD(const TwoD & Array)
{
    // this is an address and &is an address
    
    maxcol = Array.Maxcol();
    maxRows = Array.Maxrows();
    usedcol = Array.Usedcol();
    usedRows = Array.UsedRows();
    pointer = new D_var[maxRows];
    
    for(int i = 0;i<maxRows;i++)
    {
        
        pointer[i] = new double[maxcol];
        
    }
    // fill array Full of elements 
    for(int i =0;i<Array.Maxrows();i++) 
        for(int j = 0;j<Array.Maxcol();j++)
        {
            
            pointer[i][j] = Array.pointer[i][j];
            
        }
        
    
}
void TwoD::addElement(double value)
{
    
    if( (usedcol >= maxcol) && (usedRows >= maxRows))
    {
        
        
        cout<<"Error their is no more room in the Matrix"<<endl;
        return;
        
    }
    if(usedcol >= maxcol)
    {
        // change to zero
        usedcol = 0;
        usedRows++;
    }
    pointer[usedRows][usedcol] = value;
    
    usedcol++;
    return;
    
}    
    
void TwoD::Display()
{
    
    for(int m = 0;m< maxRows;m++)
    {
      cout<<"{ ";    
      for(int n = 0;n< maxcol;n++)
      {
         cout<<pointer[m][n]<<" ";
            
          
      }
      cout<<"}";
      cout<<endl;
      
    }  
}

void TwoD::rand_fill()
{
    
    for(int n = 0;n<maxRows;n++)
    {    
        
        for(int m = 0;m<maxcol;m++)
        {
            
            pointer[n][m] = (((RAND_MAX - rand())/static_cast<double>(RAND_MAX)));
            
            
        }
    
    }
    
    
}




