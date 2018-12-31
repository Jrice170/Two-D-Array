


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
    void fill_ones();
    double Getindex(int row,int col);
    
    /// operator overload
    friend TwoD operator *(const TwoD & lhs,const double scalar);  
    friend TwoD operator -(const TwoD & lhs,const double scalar);
    friend TwoD operator +(const TwoD & lhs,const double scalar);
    friend TwoD operator /(const TwoD & lhs,const double scalar);
    friend TwoD operator *(const TwoD & lhs,const TwoD & rhs);
    
    /// destructor
    
    // must have the same rows and cols
    TwoD & operator -(const TwoD & rhs);
    TwoD & operator +(const TwoD & rhs);
    TwoD & operator =(const TwoD & rhs);
    
};

int main()
{
   TwoD Matrix(6,6);
   
   TwoD Matrix2(6,6);
   cout<<"Matrix 1"<<endl;
   Matrix.rand_fill();
   Matrix2.rand_fill();
   
   Matrix.Display();
   
   cout<<"Matrix 2"<<endl;
   Matrix2.Display();
   
   int row_num, col_num;
   cout<<"Enter the current position that you want from each Matrix "<<endl;
   cin>>row_num>>col_num;
   cout<<"Matrix 1: "<<Matrix.Getindex(row_num,col_num)<<endl;
   cout<<"Matrix 2: "<<Matrix2.Getindex(row_num,col_num)<<endl;
   
   TwoD add, subtract, muliply;
   add = Matrix + Matrix2;
   cout<<"Addition "<<endl;
   add.Display();
   subtract = Matrix - (Matrix2*2);
   cout<<"subtract "<<endl;
   subtract.Display();
   muliply = Matrix * Matrix2;
   cout<<"muliply "<<endl;
   muliply.Display();
   
   cout<<" More muliply examples "<<endl;
   
   TwoD Unit(3,4), mulipler(4,3);
   mulipler.fill_ones();
   double entry;
   mulipler.Display();
  
   Unit.rand_fill();
   Unit.Display();
   
   TwoD Total;
   Total = Unit * mulipler;
   
   cout<<endl;
   
   Total.Display();
   
   
}

TwoD::TwoD(int j,int i): maxcol(i),maxRows(j),usedcol(0),usedRows(0)
{
    
     // loop 
        
        pointer = new D_var[maxRows];
        
        for(int i =0;i<maxRows;i++)
        {
            
          pointer[i] = new double[maxcol];
              
              
        }
        
    
}

/// default
TwoD::TwoD():usedcol(0),usedRows(0)
{
   maxcol = 5;
   maxRows = 5;
   
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

void TwoD::fill_ones()
{
    
    for(int n = 0;n<maxRows;n++)
    {    
        
        for(int m = 0;m<maxcol;m++)
        {
            
            pointer[n][m] = 1;
            
            
        }
    
    }
    
    
}

TwoD operator *(const TwoD & lhs,const double scalar)
{
    for(int m = 0;m< lhs.maxRows;m++)
    {
        
      for(int n = 0;n< lhs.maxcol;n++)
      {
          
         lhs.pointer[m][n] = lhs.pointer[m][n]*scalar;
            
          
      }
      
      
      
    }  
    
    
    
    TwoD copy(lhs);
    
    
    return (copy); 
    
}
TwoD operator -(const TwoD & lhs,const double scalar)
{
    for(int m = 0;m< lhs.maxRows;m++)
    {
          
      for(int n = 0;n< lhs.maxcol;n++)
      {
          
         lhs.pointer[m][n] = (lhs.pointer[m][n] - scalar);
             
          
      }
      
      
      
    }  
    
    TwoD copy(lhs);
   
    return (copy); 
}
TwoD operator +(const TwoD & lhs,const double scalar)
{
    
   for(int m = 0;m< lhs.maxRows;m++)
    {
          
      for(int n = 0;n< lhs.maxcol;n++)
      {
          
         lhs.pointer[m][n] = (lhs.pointer[m][n] + scalar);
             
          
      }
      
      
      
    }  
    TwoD copy(lhs);
    
    return (copy); 
    
    
}
TwoD operator /(const TwoD & lhs,const double scalar)
{
    
    
    for(int m = 0;m< lhs.maxRows;m++)
    {
          
      for(int n = 0;n< lhs.maxcol;n++)
      {
          
         lhs.pointer[m][n] = (lhs.pointer[m][n]/scalar); 
             
          
      }
      
      
      
    }  
    TwoD copy(lhs);
   
    return (copy);  
    
}

TwoD & TwoD::operator -(const TwoD & rhs)
{
    
    if((this->maxcol == rhs.Maxcol()) && (this->maxRows == rhs.Maxrows()))
    {
      for (int n = 0; n < this->maxRows; n++) 
      {
        
        for(int m = 0;m< this->maxcol;m++)
        {
           
           this->pointer[n][m] = (this->pointer[n][m] - rhs.pointer[n][m]);
           
           
           
        }
      
      }
      
    }
    else
    {
        
        cout<<"Must have the same rows and col "<<endl;
        exit(0);
        
    }
    
    return *this;
    
}
TwoD & TwoD::operator +(const TwoD & rhs)
{
    
    if( (this->maxcol == rhs.Maxcol()) && (this->maxRows == rhs.Maxrows()))
    {
      for (int n = 0; n < this->maxRows; n++) 
      {
        
        for(int m = 0;m< this->maxcol;m++)
        {
           
           this->pointer[n][m] = this->pointer[n][m] + rhs.pointer[n][m];
           
        }
      
      }
      
    }
    else
    {
        
        cout<<"Must have the same rows and col "<<endl;
        exit(0);
        
    }
    
    return *this;
    
}


TwoD & TwoD::operator =(const TwoD & rhs)
{
    
    if(this == &rhs)
    {
        
        return *this;
        
    }
    this->maxcol = rhs.Maxcol();
    this->maxRows = rhs.Maxrows();
    this->usedcol = rhs.Usedcol();
    this->usedRows = rhs.UsedRows();
    this->pointer = new D_var[this->maxRows];
   
    for(int i = 0;i<this->maxRows;i++)
    {
        
        this->pointer[i] = new double[this->maxcol];
        
    }
    // fill array Full of elements 
    
    for(int i =0;i<rhs.Maxrows();i++) 
        for(int j = 0;j<rhs.Maxcol();j++)
        {
            
            this->pointer[i][j] = rhs.pointer[i][j];
            
        }
    
    return *this;
    
}





TwoD operator*(const TwoD & lhs,const TwoD & rhs)
{
    
    if(lhs.maxcol == rhs.maxRows)
    {
        
        TwoD return_array(lhs.maxRows,rhs.maxcol);
        for(int n = 0;n<lhs.maxRows;n++) 
        {   
            
            for(int m =0;m<rhs.maxcol;m++)
            {
                
                for(int k =0; k <lhs.maxcol; k++)
                {
                    
                  // calculus 2 meets c++ ...... ..
                   return_array.pointer[n][m] += lhs.pointer[n][k]*rhs.pointer[k][m]; 
                   
                } 
            }
            
        }
        
        return return_array;
        
    }
    else 
    {
        
        cout<<" Error can't muliply matrix "<<endl;
        exit(0);
        
    }
    
    
    
}



double TwoD::Getindex(int row,int col)
{
    
    if((row > this->maxRows)  || (col > this->maxcol))
    {
        
        cout<<" You cant axcess that row and col"<<endl;
        return 0.0;
    }
    else
    {
        
        return (this->pointer[row][col]);
        
    }
    
    
    
    
}








