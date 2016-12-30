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

#include "../include/sys_def.h"

namespace mi_stl
{
	template <class T>
	struct BiNode
	{
		typedef T type_val;
		T data;
		BiNode<type_val>* leftNode;
		BiNode<type_val>* rightNode;
	};

	template <class _T1>
	class base_ds
	{
	public:
		typedef _T1  type_val;
		typedef _T1* type_ptr;
		typedef _T1& type_ref;
	public:
		base_ds()
		{
			_size = 0;
			_root = nullptr;
		}
		base_ds(size_t size_) : _size(size_){}
		base_ds(BiNode<_T1*>* dataptr, const size_t& node_size) : _root(dataptr), _size(node_size){}
		base_ds(const base_ds<_T1>& ins)
		{
			_size = ins._size;
			_root = ins._root;
		}
		virtual ~base_ds(){};

	protected:
		BiNode<_T1*>* _root; 
		size_t	_size;
	public:
		/*
		 *	Create a binary tree
		 */
		virtual BiNode<_T1*>* create()=0;

		/*
		 *	Get the root node of binary tree
		 */
		virtual BiNode<_T1*>* get_root()const=0;

		/*
		 *	
		 */
		virtual size_t get_size()const
		{
			return _size;
		}

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
	template <class _T>
	class base_binary : public base_ds<_T>
	{
	public:
		base_binary(const size_t& _size) : base_ds(_size){}
		base_binary(BiNode<_T*>* dataptr):base_ds(dataptr){}
		~base_binary(){};

		virtual BiNode<_T*>* create();
		
		virtual BiNode<_T*>* get_root()const;
		
		virtual void pre_order(BiNode<_T*>* root);

		virtual void mid_order(BiNode<_T*>* root);
		
		virtual void post_order(BiNode<_T*>* root);

		virtual void level_order(BiNode<_T*>* root);

		virtual void release(BiNode<_T*>* root);

	protected:
	private:
	};

	template<class _T>
	BiNode<_T*>* base_binary<_T>::create()
	{
		BiNode<_T*> * root;
		_T* data = new _T;
		if (_size == 0)
			root = NULL;
		else
		{ 
			root = new BiNode<_T*>;       //生成一个结点
			root->data = data;
			root->leftNode = create();    //递归建立左子树
			root->rightNode = create();    //递归建立右子树
		} 

		return root;
	}

	template<class _T>
	BiNode<_T*>* base_binary<_T>::get_root()const
	{
		return _root;
	}

	template<class _T>
	void base_binary<_T>::pre_order(BiNode<_T*>* root)
	{
	}

	template<class _T>
	void base_binary<_T>::mid_order(BiNode<_T*>* root)
	{
	}

	template<class _T>
	void base_binary<_T>::post_order(BiNode<_T*>* root)
	{
	}

	template<class _T>
	void base_binary<_T>::level_order(BiNode<_T*>* root)
	{
	}

	template<class _T>
	void base_binary<_T>::release(BiNode<_T*>* root)
	{
	}
}

#endif // !_DS_H_
