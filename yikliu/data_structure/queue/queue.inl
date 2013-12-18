//
// size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
	return this->tail_ - this->head_;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
	return this->head_ == -1;
}


