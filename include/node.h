#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template<class VT>
class Node
{
public:
	Node *Next;
	VT key;
	Node();
	Node(const VT&);
};

template<class VT>
Node<VT>::Node();

template<class VT>
Node<VT>::Node(const VT&);
