//*********************************************************************************/
// MIT License
//
// Copyright (c) 2016 RedFree
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//*********************************************************************************/

#ifndef _DS_H_
#define _DS_H_

#include "sys_def.h"

namespace mi_stl
{
	template <class _T>
	struct BiNode
	{
		typedef _T type_val;
		_T data;
		BiNode<type_val>* leftNode;
		BiNode<type_val>* rightNode;
	};

	template <class _T, class _Td>
	class base_ds
	{
	public:
		typedef _T  type_val;
		typedef _T* type_ptr;
		typedef _T& type_ref;
	public:
		base_ds()
		{
			_size = 0;
			_root = nullptr;
		}
		base_ds(size_t size_) : _size(size_){}
		base_ds(BiNode<_T*>* dataptr, const size_t& node_size) : _root(dataptr), _size(node_size){}
		base_ds(const base_ds<_T, _Td>& ins)
		{
			_size = ins._size;
			_root = ins._root;
		}
		virtual ~base_ds(){};

		BiNode<_T*>* _root; 
		size_t	_size;
		size_t  _deep;
	public:
		/*
		 *	Create a binary tree
		 */
		virtual BiNode<_T*>* create()=0;

		/*
		 *	Get the root node of binary tree
		 */
		virtual BiNode<_T*>* get_root()const=0;

		/*
		 *	
		 */
		virtual size_t get_size()const
		{
			return _size;
		}

		size_t get_deep_of_tree()const
		{
			size_t val = log(_size+1);
			_deep = val/log(2) - 1;


			return _deep;
		}

		virtual void fill_tree(BiNode<_T*>* root, _T*)=0;

		/*
		 *	Previous order traversal
		 */
		virtual void pre_order(BiNode<type_ptr>* root)=0;

		/*
		 *	Middle order traversal
		 */
		virtual void mid_order(BiNode<type_ptr>* root)=0;

		/*
		 *	postorder
		 */
		virtual void post_order(BiNode<type_ptr>* root)=0;

		/*
		 *	lever order
		 */
		virtual void level_order(BiNode<type_ptr>* root)=0;

		/*
		 *	release resource
		 */
		virtual void release(BiNode<type_ptr>* root)=0;
	};

	/*
	 *	Base binary tree
	 */
	template <class _T, class _Td>
	class base_binary : public base_ds<_T, _Td>
	{
	public:
		base_binary(const size_t& size_) : base_ds<_T, _Td>(size_){_this_deep = 0; _this_count = 0;}
		base_binary(BiNode<_T*>* dataptr):base_ds<_T, _Td>(dataptr){}
		~base_binary(){};

		virtual BiNode<_T*>* create();
		
		virtual BiNode<_T*>* get_root()const;
	
		virtual void fill_tree(BiNode<_T*>* root, _T* node_data);

		virtual void pre_order(BiNode<_T*>* root);

		virtual void mid_order(BiNode<_T*>* root);
		
		virtual void post_order(BiNode<_T*>* root);

		virtual void level_order(BiNode<_T*>* root);

		virtual void release(BiNode<_T*>* root);

	protected:
		
	private:

		/*count of creating the tree*/
		size_t _this_count;
		size_t _this_deep;
		
	};

	/*
	*	Create node
	*
	*/
	template <class _T, class _Td>
	BiNode<_T*>* base_binary<_T, _Td>::create()
	{
		std::vector<BiNode<_T*>*> v(base_ds<_T, _Td>::_size);
		for (int i = 0; i < base_ds<_T, _Td>::_size; ++i)
		{
			v[i] = new BiNode<_T*>;
			v[i]->data = new _T;
		}

		for (size_t i = 0; i < base_ds<_T, _Td>::_size; ++i)
		{
			if (2*i+1 < base_ds<_T, _Td>::_size)
			{
				v[i]->leftNode = v[2*i+1];
			}

			if (2*i + 2 < base_ds<_T, _Td>::_size)
			{
				v[i]->rightNode = v[2*i+2];
			}
		}

		base_ds<_T, _Td>::_root = v[0];

		return v[0];
	}

	template <class _T, class _Td>
	BiNode<_T*>* base_binary<_T, _Td>::get_root()const
	{
		return base_ds<_T, _Td>::_root;
	}

	// fill the tree with data
	template <class _T, class _Td>
	void base_binary<_T, _Td>::fill_tree(BiNode<_T*>* root, _T* node_data)
	{
		if (root != nullptr && node_data != nullptr)
		{
			
			_T* tmp = node_data;
			if (root->leftNode != nullptr)
			{
				cout << "leftNode = " << (*(node_data)) << endl;
				fill_tree(root->leftNode, ++node_data);
			}

			if (root->rightNode != nullptr)
			{
				cout << "rightNode = " << (*(node_data)) << endl;
				fill_tree(root->rightNode, ++node_data);
			}
			
			
			if (node_data == tmp)
			{
				++node_data;
			}
			root->data = tmp;
		}
		else
		{
			if (node_data != nullptr)
			{
				--node_data;
			}
			
		}
	}

	template <class _T, class _Td>
	void base_binary<_T, _Td>::pre_order(BiNode<_T*>* root)
	{
		//cout << "pre_order" << endl;
		if (root != nullptr)
		{
			if (root->data != nullptr)
			{
				cout << "data = " << *(root->data) << endl;
			}
			pre_order(root->leftNode);
			pre_order(root->rightNode);
		}
	}

	template <class _T, class _Td>
	void base_binary<_T, _Td>::mid_order(BiNode<_T*>* root)
	{
	}

	template <class _T, class _Td>
	void base_binary<_T, _Td>::post_order(BiNode<_T*>* root)
	{
	}

	template <class _T, class _Td>
	void base_binary<_T, _Td>::level_order(BiNode<_T*>* root)
	{
	}

	/*release all the memory*/
	template <class _T, class _Td>
	void base_binary<_T, _Td>::release(BiNode<_T*>* root)
	{
		if (root != nullptr)
		{
			release(root->leftNode);
			release(root->rightNode);
			if (root->data != nullptr)
			{
				delete root->data;	
			}
			delete root;			
		}
	}
}

#endif // !_DS_H_
