//
// Created by aboulfotouh on 5‏/10‏/2026.
//

#ifndef CPPARRAYLIST_SPARSEMATRIX_H
#define CPPARRAYLIST_SPARSEMATRIX_H
#include "MatrixNode.h"

#include "ArrayList.h"
#include "Node.h"
#include <iostream>
#include <unistd.h>
using namespace std;
class SparseMatrix
{
public:
   MatrixNode* Head;
   int rows;
   int columns;
   SparseMatrix(int rows, int columns)
   {
      Head = nullptr;
      this->rows =rows;
      this->columns =columns;

   }
   MatrixNode* search_by_index(int idx)
   {
      for (MatrixNode* cur = Head; cur ; cur = cur->next)
      {
         if (cur->index == idx)
            return cur;
      }
      return nullptr;
   }
   void link(MatrixNode* first, MatrixNode* second,bool middle)
   {
      MatrixNode* first_next = nullptr;
      if (first != nullptr)
      {
         first_next = first->next;
         first->next = second;

      }

      if (second != nullptr)
      {
         second->prev = first;
      }
      if (middle)
      {
         if (second)
            second->next = first_next;
         if (first_next)
            first_next->prev = second;
      }


   }
   MatrixNode* search_first_lest_idex(int idx)
   {
      MatrixNode* previous = nullptr;
      for (MatrixNode* cur = Head ; cur ; cur = cur->next)
      {
         if (cur->index <= idx)
            previous =  cur;
      }
      return previous;
   }
   //index == row
   void set_value(int value, int row,int  col)
   {
      MatrixNode* node = search_by_index(row);
      if (node)
      {
         node->subList->set_value(value,col);
      }
      else
      {
         MatrixNode* newNode = new MatrixNode(this->columns,row);
         newNode->subList->set_value(value,col);

         if (Head == nullptr)
         {
            Head = newNode;
         }
         else
         {
            MatrixNode* pervious = search_first_lest_idex(row);
            bool is_middle =false;

            if (pervious == nullptr)
            {
               link(newNode , Head,is_middle);
               Head = newNode;
            }
            else
            {
               if (pervious->next)
                  is_middle =true;
               link(pervious,newNode,is_middle);
            }

         }
      }
   }
   void add(SparseMatrix mat)
   {
      for (MatrixNode* cur = mat.Head ;cur;cur = cur->next )
      {
         MatrixNode* wanted_node = this->search_by_index(cur->index);
         if (wanted_node)
         {
            wanted_node->subList->add(*cur->subList);
         }
         else
         {
            for (Node* curr = cur->subList->Head ; curr ;curr = curr->next)
            {
               this->set_value(curr->data,cur->index,curr->index);
            }
         }


      }

   }
   void print_matrix()
   {
      for (MatrixNode* cur = Head ;cur ; cur = cur->next)
      {
         cur->subList->print_arry();
         cout<<endl;
      }
   }
   void print_matrix_nonzero()
   {
      for (MatrixNode* cur = Head ;cur ; cur = cur->next)
      {
         cur->subList->print_arry_non_zero();
         cout<<endl;

      }
   }
};


#endif //CPPARRAYLIST_SPARSEMATRIX_H
