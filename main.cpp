/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/01 19:30:23 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iterator> 
#include <iostream>
#include "vector.hpp"
#include <vector>

// int main ()
// {try
// {
//         //  std::vector<int> myvector;
//       ft::vector<int> myvector;
//    int j = 11;
//    while (j > 0)
//    {
//       myvector.push_back(j);
//       j--;
//    }
//   std::cout<< "size "<< myvector.size() << std::endl;
//   std::cout<< "capasity "<< myvector.capacity() << std::endl;
//   // std::cout<< "at "<< myvector.at(2) << std::endl;
//   // std::cout<< "front "<< myvector.front() << std::endl;
//   // std::cout<< "back "<< myvector.back() << std::endl;
//   // std::cout<< "data "<< myvector.data()[8]<< std::endl;
//   // std::cout<< "begin "<< *myvector.begin()<< std::endl;
//   // std::cout<< "end "<< *myvector.end()<< std::endl;
//   std::cout << "myvector contains:\n";
//   for (int i=0;i < (int )myvector.size();i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//     myvector.insert(myvector.end(), myvector.begin() ,myvector.end());
//  // ft::vector<int>vctor(myvector.begin(), myvector.end());
//   std::cout << *(myvector.rbegin() - 3)<<std::endl;
//   std::cout << *(myvector.rend() + 3)<<std::endl;
//   std::cout <<*(myvector.begin() + 3)<<std::endl;
//   std::cout <<*(myvector.end()-3)<<std::endl;
//   // std::cout<< "size "<< myvector.size() << std::endl;
//   // std::cout<< "capasity "<< myvector.capacity() << std::endl;
//   // std::cout << "myvector contains:\n";
//   // for (int i=0;i < (int )myvector.size();i++)
//   //   std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//   }
//   catch(const std::exception& e){
//     std::cerr << e.what() << '\n';
//   }
//     return 0;
// }

#include <iostream>
#include <map>
#include <string>
#include "map.hpp"

int main ()
{
  try
  {
     ft::map<char,int> mymap;
      mymap.insert (ft::pair<char,int>('a',1));
    
      mymap.insert (ft::pair<char,int>('b',2));
      mymap.insert (ft::pair<char,int>('c',3));
      mymap.insert (ft::pair<char,int>('d',4));
      mymap.insert (ft::pair<char,int>('e',5));
      mymap.insert (ft::pair<char,int>('f',6));
      mymap.insert (ft::pair<char,int>('j',7));
      mymap.insert (ft::pair<char,int>('k',8));
      mymap.insert (ft::pair<char,int>('l',9));
      mymap.insert (ft::pair<char,int>('m',10));
      mymap.insert (ft::pair<char,int>('n',11));
      //mymap.print(" ", 1);
      // std::cout<<"size -->"<<mymap.size()<<std::endl;
      //  mymap.clear();
      // std::cout<<"size -->"<<mymap.size()<<std::endl;
      // mymap['u']=56;
      // std::cout<<"max size -->"<<mymap.max_size()<<std::endl;
      // std::cout<<"at -->"<<mymap.at('u')<<std::endl;
      // if (mymap.empty()){
      //     std::cout<<"is empty "<<std::endl;
      // }else{
      //     std::cout<<"is not emty"<<std::endl;
      // }
      // std::cout<<"begin -->"<< mymap.begin()->second <<std::endl;
      // // mymap.end();
      // std::cout<<"end -->"<< mymap.end()->second<<std::endl;
      // mymap.print(" ", 1);
      // std::cout <<"R_prnt------->"<<mymap.avl_tree.root->left->right->parent->data->second<<std::endl;
      // std::cout <<"R_chld------->"<<mymap.avl_tree.root->left->right->data->second<<std::endl;
      // std::cout <<"L_prnt------->"<<mymap.avl_tree.root->left->left->parent->data->second<<std::endl;
      // std::cout <<"L_chld------->"<<mymap.avl_tree.root->left->left->data->second<<std::endl;
      // mymap.insert (mymap.begin(), ft::pair<char,int>('a',22222));
        // mymap.print(" ", 1);
     //  std::cout << "m['a'] = " << mymap['a'] << std::endl;  
      ft::map<char,int> secondmap;
      secondmap.insert(mymap.begin(), mymap.end());
      secondmap.print(" ", 1);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  

  return 0;
}
