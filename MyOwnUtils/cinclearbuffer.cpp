#include <iostream>

template <typename T>
T readValue(std::istream &is = std::cin)
{
	T t = T();

	while (true)
	{
		std::cout << " " << std::flush;
		is >> t;

		if (is.fail())
		{
			is.clear();
			is.ignore(1);
		}
		else
		{
			if (!is.eof())
			{
				std::istream::char_type c = std::istream::traits_type::to_char_type(is.peek());

					if (std::use_facet<std::ctype<std::istream::char_type> >(is.getloc()).is(std::ctype_base::space, c))
					{
						is.ignore(1);
						return t;
					}
					else
					{
						is.ignore(1);
					}
			}
			else
			{
				return t;
			}
		}
		std::cout << std::endl << "   WARNING!!!!   No Valid Entry!   Please try again:";
	}
}	