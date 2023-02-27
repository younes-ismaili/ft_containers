/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:45:39 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/27 18:16:53 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <memory>

namespace ft {
template<typename T, class Allocator = std::allocator<T> >
class node_avl
{
  public:
          T        *data;
          node_avl *left;
          node_avl *right;
          node_avl *parent;
          size_t    height;

          node_avl(){
            data = NULL;
            left = NULL;
            right = NULL;
            parent = NULL;
            height = 0;
            
          }
          
          node_avl (const T & data_){
            data = alloc.allocate(1);
            alloc.construct(data, data_);
            left = NULL;
            right = NULL;
            parent = NULL;
            height = 1;
          }
          
          node_avl operator=(node_avl const &other){
          if (this != other){  
            if (data){
              alloc.deallcate(data, 1);
            }else{
              data = alloc.allocate(1);
              alloc.construct(data, *(other.data));
              left = other.left;
              right = other. right;
              parent = other.parent;
            }
          }
          }
          ~node_avl(){}
    private:
           Allocator alloc;
};
}
#endif