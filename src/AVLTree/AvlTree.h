/*******************************************************************************
Title           : AvlTree.h
Author          : Stewart Weiss
Modifications   : made by Keisuke Suzuki on Aug 03, 2019
                  added getSameZip() and getCloseElem()

License         : Copyright 2020 Keisuke Suzuki, based on code written by
    Stewart Weiss, copyrighted under the GPLv3, 2019

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*******************************************************************************/

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "../Tree/tree.h"

// Node and forward declaration because g++ does
// not understand nested classes.
template < class Comparable >
    class AvlTree;

template < class Comparable >
    class AvlNode
    {
        
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;
        
        AvlNode( const Comparable &theElement,
                 AvlNode *lt,
                 AvlNode *rt,
                 int h = 0 )
        : element(theElement), left(lt), right(rt), height(h)
        {
        }
        
        friend class AvlTree<Comparable>;
    };

#include <iostream>

template < class Comparable >
    class AvlTree
    {
        public:
        
        explicit AvlTree( const Comparable &notFound );
        
        AvlTree( const AvlTree &rhs );
        
        ~AvlTree();
        
        const Comparable &findMin() const;
        
        const Comparable &findMax() const;
        
        const Comparable &find( const Comparable &x ) const;
        
        list <Comparable> getSameZip( const Comparable &x ) const;
        
        list <Comparable> getCloseElem( const Comparable &x,
                                        double distance ) const;
        
        bool isEmpty() const;
        
        void printTree() const;
        
        void makeEmpty();
        
        void insert( const Comparable &x );
        
        const AvlTree &operator=( const AvlTree &rhs );
        
        private:
        
        AvlNode<Comparable> *root;
        
        const Comparable ITEM_NOT_FOUND;
        
        const Comparable &elementAt( AvlNode<Comparable> *t ) const;
        
        void insert( const Comparable &x, AvlNode<Comparable> *&t ) const;
        
        AvlNode<Comparable> *findMin( AvlNode<Comparable> *t ) const;
        
        AvlNode<Comparable> *findMax( AvlNode<Comparable> *t ) const;
        
        AvlNode<Comparable> *find( const Comparable &x, AvlNode<Comparable> *t )
        const;
        
        list <Comparable> getSameZip( const Comparable &x,
                                      AvlNode<Comparable>
                                      *t ) const;
        
        list <Comparable> getCloseElem( const Comparable &x,
                                        AvlNode<Comparable> *t, double
                                        distance ) const;
        
        void makeEmpty( AvlNode<Comparable> *&t ) const;
        
        void printTree( AvlNode<Comparable> *t ) const;
        
        AvlNode<Comparable> *clone( AvlNode<Comparable> *t ) const;
        
        // Avl manipulations
        int height( AvlNode<Comparable> *t ) const;
        
        int max( int lhs, int rhs ) const;
        
        void rotateWithLeftChild( AvlNode<Comparable> *&k2 ) const;
        
        void rotateWithRightChild( AvlNode<Comparable> *&k1 ) const;
        
        void doubleWithLeftChild( AvlNode<Comparable> *&k3 ) const;
        
        void doubleWithRightChild( AvlNode<Comparable> *&k1 ) const;
    };

#endif //_AVL_TREE_H_
