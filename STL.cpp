/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   STL.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:43:47 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/12 11:47:04 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include <stack>
#include <iostream>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  try
   {
      /*-------------tests for vector ---------------*/
      
      /*-------------Construct vector -----------------------*/
     { std::vector<int> first;                                // empty vector of ints
      std::vector<int> second (4,100);   
      std::cout << second.size() << "\n";                   // four ints with value 100
      std::vector<int> third (second.begin(),second.end());  // iterating through second
      std::vector<int> fourth (third);                       // a copy of third
      // the iterator constructor can also be used to construct from arrays:
      int myints[] = {16,2,77,29};
      std::vector<int> fistdh (myints, myints + sizeof(myints) / sizeof(int) );

      std::cout << "The contents of fistdh are:";
      for (std::vector<int>::iterator it = fistdh.begin(); it != fistdh.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';
     }

      /*----------------operator=-----------------*/
     { std::vector<int> foo (3,0);
      std::vector<int> bar (5,0);
      
      bar = foo;
      foo = std::vector<int>();

      std::cout << "Size of foo: " << int(foo.size()) << '\n';
      std::cout << "Size of bar: " << int(bar.size()) << '\n';
    }
      /*-----------------Iterators ----------------*/
      {
      std::vector<int> myvector;
      for (int i=1; i<=5; i++) myvector.push_back(i);

      std::cout << "myvector contains:";
      for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';
      }
      /*----------------reverse iterator------------*/
      {
      std::vector<int> myvector1 (5);  // 5 default-constructed ints
        int i=0;
       std::vector<int>::reverse_iterator rit = myvector1.rbegin();
         for (; rit != myvector1.rend(); ++rit){
           *rit = ++i;
         }

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
        }
      /*------------Assign vector content--------------------*/
      {
      std::vector<int> first1;
      std::vector<int> second1;
      std::vector<int> third1;

      first1.assign (7,100);             // 7 ints with a value of 100

      std::vector<int>::iterator it;
      it = first1.begin()+1;

      second1.assign (it,first1.end()-1); // the 5 central values of first1
      int myints1[] = {1776,7,4};
      third1.assign (myints1,myints1+3);   // assigning from array.

      std::cout << "Size of first1: " << int (first1.size()) << '\n';
      std::cout << "Size of second1: " << int (second1.size()) << '\n';
      std::cout << "Size of third1: " << int (third1.size()) << '\n';
      }
      /*------------------at--------------------------*/
      {
      std::vector<int> myvector2 (10);   // 10 zero-initialized ints
      // assign some values:
      for (unsigned i=0; i<myvector2.size(); i++)
        myvector2.at(i)=i;

      std::cout << "myvector2 contains:";
      for (unsigned i=0; i<myvector2.size(); i++)
        std::cout << ' ' << myvector2.at(i);
      std::cout << '\n';
      }
      /*-----------------back-----------------------*/
      {
      std::vector<int> myvector3;

      myvector3.push_back(10);

      while (myvector3.back() != 0)
      {
        myvector3.push_back ( myvector3.back() -1 );
      }

      std::cout << "myvector3 contains:";
      for (unsigned i=0; i<myvector3.size() ; i++)
        std::cout << ' ' << myvector3[i];
      std::cout << '\n';
    }
    /*---------------capacity-----------------------*/
    {
      std::vector<int> myvector4;

      // set some content in the vector:
      for (int i=0; i<100; i++)
        myvector4.push_back(i);

      std::cout << "size: " << (int) myvector4.size() << '\n';
      std::cout << "capacity: " << (int) myvector4.capacity() << '\n';
      std::cout << "max_size: " << (int) myvector4.max_size() << '\n';
    }
    /*---------------clear----------------------------*/

      {
      std::vector<int> myvector;
      myvector.push_back (100);
      myvector.push_back (200);
      myvector.push_back (300);

      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';

      myvector.clear();
      myvector.push_back (1101);
      myvector.push_back (2202);

      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    
    /*-------------data------------------------*/
    {
      std::vector<int> myvector (5);
      int* p = myvector.data();
      *p = 10;
      ++p;
      *p = 20;
      p[2] = 100;
      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    /*--------------empty----------------------*/

    {
      std::vector<int> myvector;
      int sum (0);

      for (int i=1;i<=10;i++) myvector.push_back(i);

      while (!myvector.empty())
      {
        sum += myvector.back();
        myvector.pop_back();
      }

      std::cout << "total: " << sum << '\n';
    }
    
    /*---------------erase----------------------------*/

    {
    std::vector<int> myvector;
      // set some values (from 1 to 10)
      for (int i=1; i<=10; i++) 
        myvector.push_back(i);

      // erase the 6th element
      myvector.erase (myvector.begin()+5);

      // erase the first 3 elements:
      myvector.erase (myvector.begin(),myvector.begin()+3);

      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    /*-----------------------get_allocator--------------*/

      {
      std::vector<int> myvector;
      int * p;
      unsigned int i;

      // allocate an array with space for 5 elements using vector's allocator:
      p = myvector.get_allocator().allocate(5);

      // construct values in-place on the array:
      for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

      std::cout << "The allocated array contains:";
      for (i=0; i<5; i++) std::cout << ' ' << p[i];
      std::cout << '\n';

      // destroy and deallocate:
      for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
      myvector.get_allocator().deallocate(p,5);
    }
    /*--------------------insert----------------------*/
    {
      std::vector<int> myvector (3,100);
      std::vector<int>::iterator it;

      it = myvector.begin();
      it = myvector.insert (it, 200 );
     
     myvector.insert(it, 2, 300);
     // "it" no longer valid, get a new one:
     it = myvector.begin();

      std::vector<int> anothervector (2,400);
      myvector.insert (it+2,anothervector.begin(),anothervector.end());

       int myarray [] = { 501,502,503 };
       myvector.insert (myvector.begin(), myarray, myarray+3);

      std::cout << "myvector contains:";
      for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
      std::cout << '\n';
    }
    /*----------------max_size-------------------------*/

    {
     std::vector<int> myvector;
      // set some content in the vector:
      for (int i=0; i<100; i++) 
          myvector.push_back(i);
      std::cout << "size: " << myvector.size() << "\n";
      std::cout << "capacity: " << myvector.capacity() << "\n";
      std::cout << "max_size: " << myvector.max_size() << "\n";
    }

    /*--------------------operator[]-------------------*/

    {
      std::vector<int> myvector (10);   // 10 zero-initialized elements

      std::vector<int>::size_type sz = myvector.size();

      // assign some values:
      for (unsigned i=0; i<sz; i++) myvector[i]=i;

      // reverse vector using operator[]:
      for (unsigned i=0; i<sz/2; i++)
      {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
      }

      std::cout << "myvector contains:";
      for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';

    }

    /*----------------operator=------------------------*/

    {
      std::vector<int> foo (3,0);
      std::vector<int> bar (5,0);

      bar = foo;
      foo = std::vector<int>();

      std::cout << "Size of foo: " << int(foo.size()) << '\n';
      std::cout << "Size of bar: " << int(bar.size()) << '\n';
    }

    /*---------------pop_back-----------------------*/
    
    {
      std::vector<int> myvector;
      int sum (0);
      myvector.push_back (100);
      myvector.push_back (200);
      myvector.push_back (300);

      while (!myvector.empty())
      {
        sum+=myvector.back();
        myvector.pop_back();
      }
      std::cout << "The elements of myvector add up to " << sum << '\n';
    }
    
    /*-----------------push_back----------------------*/

    {
     std::vector<int> myvector;
      int myint[] = {1,2,3,4,5,6,7,8,9};
      int i = 0;
       while (myint[i]){
        myvector.push_back (myint[i++]);
      }
      std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    }
    
    /*------------------reserve------------------------*/

    {
      std::vector<int>::size_type sz;

      std::vector<int> foo;
      sz = foo.capacity();
      std::cout << "making foo grow:\n";
      for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
          sz = foo.capacity();
          std::cout << "capacity changed: " << sz << '\n';
        }
      }
      std::vector<int> bar;
      sz = bar.capacity();
      bar.reserve(100);   // this is the only difference with foo above
      std::cout << "making bar grow:\n";
      for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
          sz = bar.capacity();
          std::cout << "capacity changed: " << sz << '\n';
        }
      }
    }
    
    /*----------------resize-------------------------*/
    {
      std::vector<int> myvector;

      // set some initial content:
      for (int i=1;i<10;i++) 
        myvector.push_back(i);

      myvector.resize(5);
      myvector.resize(8,100);
      myvector.resize(12);

      std::cout << "myvector contains:";
      for (int i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    
    /*-----------------size---------------------------*/
    {
     std::vector<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';

      for (int i=0; i<10; i++) myints.push_back(i);
      std::cout << "1. size: " << myints.size() << '\n';

      myints.insert (myints.end(),10,100);
      std::cout << "2. size: " << myints.size() << '\n';

      myints.pop_back();
      std::cout << "3. size: " << myints.size() << '\n';
    }
    /*-------------------swap-------------------------*/

    {
     std::vector<int> foo (3,100);   // three ints with a value of 100
     std::vector<int> bar (5,200);   // five ints with a value of 200

      foo.swap(bar);

      std::cout << "foo contains:";
      for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
      std::cout << '\n';

      std::cout << "bar contains:";
      for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
      std::cout << '\n';
    }
    /*-----------------------relational operators------------*/

    {
      std::vector<int> foo (3,100);   // three ints with a value of 100
      std::vector<int> bar (2,200);   // two ints with a value of 200

      if (foo==bar) std::cout << "foo and bar are equal\n";
      if (foo!=bar) std::cout << "foo and bar are not equal\n";
      if (foo< bar) std::cout << "foo is less than bar\n";
      if (foo> bar) std::cout << "foo is greater than bar\n";
      if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
      if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    }
    /*-----------------swap (vector)-----------------------*/

    {
      unsigned int i;
      std::vector<int> foo (3,100);   // three ints with a value of 100
      std::vector<int> bar (5,200);   // five ints with a value of 200

      foo.swap(bar);

      std::cout << "foo contains:";
      for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';

      std::cout << "bar contains:";
      for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';

    }
    /*---------------------------------tests for stack ------------------------------------*/
    /*-----------------------push---------------*/
    {
      std::stack<int> mystack;
      int sum (0);

      for (int i=1;i<=10;i++) mystack.push(i);

      while (!mystack.empty())
      {
        sum += mystack.top();
        mystack.pop();
      }

      std::cout << "total: " << sum << '\n';

      /*------------push and pop---------------*/
      std::stack<int> mystack1;

      for (int i=0; i<5; ++i) mystack1.push(i);

      std::cout << "Popping out elements...";
      while (!mystack1.empty())
      {
        std::cout << ' ' << mystack1.top();
        mystack1.pop();
      }
      std::cout << '\n';
      /*--------------size----------------*/
     std::stack<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';

      for (int i=0; i<5; i++) myints.push(i);
      std::cout << "1. size: " << myints.size() << '\n';

      myints.pop();
      std::cout << "2. size: " << myints.size() << '\n';
      /*------------top---------------------*/

      std::stack<int> mystack2;
      mystack2.push(10);
      mystack2.push(20);

      mystack2.top() -= 5;

      std::cout << "mystack2.top() is now " << mystack2.top() << '\n';
      
      /*--------------comparition--------------*/
      std::stack<int> alice;
      std::stack<int> bob;
      std::stack<int> eve;
      alice.push(1);
      alice.push(2);
      alice.push(3);
      
      bob.push(8);
      bob.push(9);
      bob.push(10);
      
      eve.push(1);
      eve.push(2);
      eve.push(3);
      std::cout << std::boolalpha;
      // Compare non equal containers
      std::cout << "alice == bob returns " << (alice == bob) << '\n';
      std::cout << "alice != bob returns " << (alice != bob) << '\n';
      std::cout << "alice <  bob returns " << (alice < bob) << '\n';
      std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
      std::cout << "alice >  bob returns " << (alice > bob) << '\n';
      std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
  
      std::cout << '\n';
  
      // Compare equal containers
      std::cout << "alice == eve.push(n)s " << (alice == eve) << '\n';
      std::cout << "alice != eve returns " << (alice != eve) << '\n';
      std::cout << "alice <  eve returns " << (alice < eve) << '\n';
      std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
      std::cout << "alice >  eve returns " << (alice > eve) << '\n';
      std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
   }
  /*----------------test for map ----------------------------------------------*/
  /*----------------------Construct map-----------------*/
    {
      std::map<char,int> first;
      first['a']=10;
      first['b']=30;
      first['c']=50;
      first['d']=70;
      
      std::cout<<"element of map --> "<<first['a']<<std::endl;
      std::cout<<"element of map --> "<<first['b']<<std::endl;
      std::cout<<"element of map --> "<<first['c']<<std::endl;
      std::cout<<"element of map --> "<<first['d']<<std::endl;
      
      std::map<char,int> second (first.begin(),first.end());
      std::cout<<"begin of map --> "<<second.begin()->second<<std::endl;
      std::cout<<"end of map --> "<<second.end()->second<<std::endl;
      std::map<char,int> third (second);
      std::cout<<"begin of second --> "<<third.begin()->second<<std::endl;
    }
    /*--------------------begin--------------------------*/
    {
      std::map<char,int> mymap;

      mymap['a'] = 10;
      mymap['b'] = 20;
      mymap['c'] = 30;
     
      // show content:
      for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';
    }
    
    /*-------------------------clear--------------------------*/
    {
      std::map<char,int> mymap;

      mymap['x']=100;
      mymap['y']=200;
      mymap['z']=300;

      std::cout << "mymap contains:\n";
      for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

      mymap.clear();
      mymap['a']=1101;
      mymap['b']=2202;

      std::cout << "mymap contains:\n";
      for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    }
    /*-----------------------------count------------------------*/
    {
      std::map<char,int> mymap;
      char c;

      mymap ['a']=101;
      mymap ['c']=202;
      mymap ['f']=303;

      for (c='a'; c<'h'; c++)
      {
        std::cout << c;
        if (mymap.count(c)>0)
          std::cout << " is an element of mymap.\n";
        else 
          std::cout << " is not an element of mymap.\n";
      }
    }
    /*----------------empty--------------------------------*/
    {
      std::map<char,int> mymap;

      mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;

      while (!mymap.empty())
      {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin());
      }
    }

    /*------------------equal_range-------------------*/
    {
      std::map<char,int> mymap;

      mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;

      std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
      ret = mymap.equal_range('b');

      std::cout << "lower bound points to: ";
      std::cout << ret.first->first << " => " << ret.first->second << '\n';

      std::cout << "upper bound points to: ";
      std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }
    
    /*-------------------------erase----------------------------*/ 

    {
     std::map<char,int> mymap;
     std::map<char,int>::iterator it;

      // insert some values:
      mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;
      mymap['d']=40;
      mymap['e']=50;
      mymap['f']=60;

      it = mymap.find('b');
      mymap.erase (it);  // erasing by iterator 
                      
      std::cout<<" Astder erasing by iterator\n";
      for ( std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
          
      mymap.erase ('c');                  // erasing by key
      std::cout<<" Astder  erasing by key\n";
      for ( std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
        
      it=mymap.find ('e');
      mymap.erase (mymap.begin(), it);    // erasing by range
      // show content:
       std::cout<<" Astder  erasing by range\n";
      for ( std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }
    /*-----------------find----------------*/

    {
      std::map<char,int> mymap;
      std::map<char,int>::iterator it;

      mymap['a']=50;
      mymap['b']=100;
      mymap['c']=150;
      mymap['d']=200;
      
      // print content:
      std::cout << "elements in mymap:" << '\n';
      std::cout << "a => " << mymap.find('a')->second << '\n';
      std::cout << "c => " << mymap.find('c')->second << '\n';
      std::cout << "d => " << mymap.find('d')->second << '\n';
    }

    /*---------------get_allocator--------------------*/

    {
      int psize;
      std::map<char,int> mymap;
      std::pair<const char,int>* p;

      // allocate an array of 5 elements using mymap's allocator:
      p=mymap.get_allocator().allocate(5);

      // assign some values to array
      psize = sizeof(std::map<char,int>::value_type)*5;

      std::cout << "The allocated array has a size of " << psize << " bytes.\n";

      mymap.get_allocator().deallocate(p,5);
    }
    /*-----------------insert----------------*-----------*/ 
    
    {
      std::map<char,int> mymap;

      // first insert function version (single parameter):
      mymap.insert ( std::pair<char,int>('a',100) );
      mymap.insert ( std::pair<char,int>('z',200) );
      std::pair<std::map<char,int>::iterator,bool> ret;
      ret = mymap.insert ( std::pair<char,int>('z',500) );
      if (ret.second==false) {
        std::cout << "element 'z' already existed\n";
        std::cout << " with a value of " << ret.first->second << '\n';
      }

     // second insert function version (with hint position):
      // std::map<char,int>::iterator it = mymap.begin();
      // mymap.insert (it,std::pair<char,int>('b',300));  // max efficiency inserting
      // mymap.insert (it,std::pair<char,int>('c',400));  // no max efficiency inserting
      
      // third insert function version (range insertion):
      std::map<char,int> anothermap;
      anothermap.insert(mymap.begin(),mymap.find('c'));
      // showing contents:
      std::cout << "mymap contains:\n";
      for (std::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

      std::cout << "anothermap contains:\n";
      for (std::map<char,int>::iterator it = anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }
    /*---------------------------key_comp------------------------*/

    {
      std::map<char,int> mymap;

      std::map<char,int>::key_compare mycomp = mymap.key_comp();

      mymap['a']=100;
      mymap['b']=200;
      mymap['c']=300;

      std::cout << "mymap contains:\n";

      char highest = mymap.begin()->first;     // key value of last element

      std::map<char,int>::iterator it = mymap.begin();
      do {
        std::cout << it->first << " => " << it->second << '\n';
      } while ( mycomp((*it++).first, highest) );
      std::cout << '\n';
    }
    
    /*------------------lower_bound-------------------------------*/ 

    {
      std::map<char,int> mymap;
      std::map<char,int>::iterator itlow,itup;

      mymap['a']=20;
      mymap['b']=40;
      mymap['c']=60;
      mymap['d']=80;
      mymap['e']=100;

      itlow=mymap.lower_bound ('b');  // itlow points to b
      itup=mymap.upper_bound ('d');   // itup points to e (not d!)

      std::cout <<"tlow points to b  "<<itlow->first << " => " <<itlow->second << '\n';
      std::cout <<"itup points to e  "<<itup->first << " => " <<itup->second << '\n';

      // print content:
      for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    }
    /*------------------------max_size----------------------------*/

    {
      int i;
      std::map<int,int> mymap;

      if (mymap.max_size()>1000)
      {
        for (i=0; i<1000; i++) mymap[i]=0;
        std::cout << "The map contains 1000 elements.\n";
      }
      else std::cout << "The map could not hold 1000 elements.\n";
    }
    
    /*--------------------------operator[]----------------------*/
    
    {
     std::map<char,std::string> mymap;

      mymap['a']="an element";
      mymap['b']="another element";
      mymap['c']=mymap['b'];

      std::cout << "mymap['a'] is " << mymap['a'] << '\n';
      std::cout << "mymap['b'] is " << mymap['b'] << '\n';
      std::cout << "mymap['c'] is " << mymap['c'] << '\n';
      std::cout << "mymap['d'] is " << mymap['d'] << '\n';

      std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    } 
    
    /*---------------------operator=----------------------------*/ 
    
      {
      std::map<char,int> first;
      std::map<char,int> second;

      first['x']=8;
      first['y']=16;
      first['z']=32;

     second = first;                // second now contains 3 ints
   

      std::cout << "Size of first: " << first.size() << '\n';
      std::cout << "Size of second: " << second.size() << '\n';
    }
    /*---------------------size----------------------------*/
    {
     std::map<char,int> mymap;
      mymap['a']=101;
      mymap['b']=202;
      mymap['c']=302;
      std::cout << "mymap.size() is " << mymap.size() << '\n';
    }
    
    /*--------------------swap----------------------------*/ 

    {
      std::map<char,int> foo,bar;

      foo['x']=100;
      foo['y']=200;

      bar['a']=11;
      bar['b']=22;
      bar['c']=33;

      foo.swap(bar);

      std::cout << "foo contains:\n";
      for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

      std::cout << "bar contains:\n";
      for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }
    
    /*-------------------upper_bound-------------------*/ 

    {
      std::map<char,int> mymap;
      std::map<char,int>::iterator itlow,itup;

      mymap['a']=20;
      mymap['b']=40;
      mymap['c']=60;
      mymap['d']=80;
      mymap['e']=100;

      itlow=mymap.lower_bound ('b');  // itlow points to b
      itup=mymap.upper_bound ('d');   // itup points to e (not d!)

      std::cout <<"tlow points to b  "<<itlow->first << " => " <<itlow->second << '\n';
      std::cout <<"itup points to e  "<<itup->first << " => " <<itup->second << '\n';

      // print content:
      // for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';
    }  
    /*--------------------value_comp--------------------------*/
    {
      std::map<char,int> mymap;

      mymap['x']=1001;
      mymap['y']=2002;
      mymap['z']=3003;

      std::cout << "mymap contains:\n";

      std::pair<char,int> highest = *mymap.begin();          // last element

      std::map<char,int>::iterator it = mymap.begin();
      do {
        std::cout << it->first << " => " << it->second << '\n';
      } while ( mymap.value_comp()(*it++, highest) );
    }
    /*----------------------non-member overloads------------------*/
    
    {
     std::map<char,int> foo,bar;
      foo['a']=100;
      foo['b']=200;
      bar['a']=10;
      bar['z']=1000;

      // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
      if (foo==bar) std::cout << "foo and bar are equal\n";
      if (foo!=bar) std::cout << "foo and bar are not equal\n";
      if (foo< bar) std::cout << "foo is less than bar\n";
      if (foo> bar) std::cout << "foo is greater than bar\n";
      if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
      if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    }  
    
     /*----------------swap (map)---------------------------*/ 
     
     {
      std::map<char,int> foo,bar;

      foo['x']=100;
      foo['y']=200;

      bar['a']=11;
      bar['b']=22;
      bar['c']=33;

      swap(foo,bar);
      
      std::cout << "foo contains:\n";
      for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

      std::cout << "bar contains:\n";
      for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }
    /*---------------------------rend---------------------------*/ /*---error hier----*/
    {
      std::map<char,int> mymap;
      mymap['x'] = 100;
      mymap['y'] = 200;
      mymap['z'] = 300;
      // show content:
      std::cout <<"rbegin --- "<< mymap.rbegin()->first << " => " <<mymap.rbegin()->second << '\n';
      std::map<char,int>::reverse_iterator rit = mymap.rbegin();
       for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit){
        std::cout << rit->first << " => " << rit->second << '\n';
      }
    }
    
  }
   
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  return 0;
}