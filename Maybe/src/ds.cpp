#include "../include/DS/ds.h"


namespace mi_stl
{
	template <class _T>
	shared_ptr<BiNode<_T*>> base_binary<_T>::create()
	{
		BiNode<_T*> * root;
		shared_ptr<_T> data(new _T);
		if (_size == 0)
			root = NULL;
		else
		{ 
			root = new BiNode<_T*>;       //����һ�����
			root->data = data;
			root->leftNode = create();    //�ݹ齨��������
			root->rightNode = create();    //�ݹ齨��������
		} 
		
		return root;
	}

	template <class _T>
	shared_ptr<BiNode<_T*>> base_binary<_T>::get_root()const
	{
		return root;
	}

	template <class _T>
	void base_binary<_T>::pre_order(BiNode<_T*>* root)
	{
	}

	template <class _T>
	void base_binary<_T>::mid_order(BiNode<_T*>* root)
	{
	}

	template <class _T>
	void base_binary<_T>::post_order(BiNode<_T*>* root)
	{
	}

	template <class _T>
	void base_binary<_T>::level_order(BiNode<_T*>* root)
	{
	}

	template <class _T>
	void base_binary<_T>::release(BiNode<_T*>* root)
	{
	}

}