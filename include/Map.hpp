#ifndef MAP_HPP
#define MAP_HPP


class IteratorMap
{
	private:
		
		
	public:
		// iterator begin();
		// iterator end();
};

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map;
class Map
{
	private:
		T* obj;
		T* key;
		Map *right;
		Map *left;
		char collor;
	public:
		map();
		explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
		~map();

		map& operator=( const map& other );
		map& operator=( map&& other );
		map& operator=( std::initializer_list<value_type> ilist );
		allocator_type get_allocator() const;

		T& at( const Key& key );
		const T& at( const Key& key ) const;
		T& operator[]( const Key& key );
		T& operator[]( Key&& key );

		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		void clear();
		std::pair<iterator, bool> insert( const value_type& value );
		std::pair<iterator, bool> insert( P&& value );
		std::pair<iterator, bool> insert( value_type&& value );
		iterator insert( iterator hint, const value_type& value );
		iterator insert( const_iterator hint, P&& value );
		iterator insert( const_iterator hint, value_type&& value );
		std::pair<iterator,bool> emplace( Args&&... args )
		void erase( iterator pos );
		void erase( iterator first, iterator last );
		size_type erase( const key_type& key );
		void swap( map& other );
		node_type extract( const_iterator position );
		node_type extract( const key_type& x );
};
#endif