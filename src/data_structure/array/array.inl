namespace ds = yikliu::data_structure;

//
// size
//
template <typename T>
inline
size_t ds::Array <T>::size (void) const
{
	return this->cur_size_;
}

//
// max_size
//
template <typename T>
inline
size_t ds::Array <T>::max_size (void) const
{
	return this->max_size_;
}
