namespace ds = yikliu::data_structure;

//
// size
//
template <typename T>
inline
size_t ds::Queue<T>::size (void) const
{
	return this->tail_ - this->head_;
}

//
// is_empty
//
template <typename T>
inline
bool ds::Queue<T>::is_empty (void) const
{
	return this->head_ == -1;
}


