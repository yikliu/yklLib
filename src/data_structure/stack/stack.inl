namespace ds = yikliu::data_structure;

//
// size
//
template <typename T>
inline
size_t ds::Stack<T>::size (void) const
{
	return this->top_ + 1;
}

//
// top
//
template <typename T>
inline
T ds::Stack<T>::top (void) const
{
	if(this->is_empty())
	{
		throw new exception::my_exception("Stack is empty");
	}
	return array_->get(top_);
}

//
// is_empty
//
template <typename T>
inline
bool ds::Stack<T>::is_empty (void) const
{
	return this->top_ == -1;
}
