template <typename T, class Allocator>
Vector<T, Allocator>::Vector(const size_t n)
{
	_n = n;
	std::allocator<T> _alloc;
	array = _alloc.allocator(_n);
}

// class Vector : public IteratorVector : public ReversIteratorVector