/*
 * Copyright (c) 2012 Anton Tyurin <noxiouz@yandex.ru>
 *
 * This file is part of Tokenparser.
 *
 * Tokenparser is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tokenparser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GIL_HPP_
#define GIL_HPP_

#include <Python.h>

class allow_threads_t{
	public:
    	inline allow_threads_t():
    		m_thread_state(PyEval_SaveThread()) {};

    	inline ~allow_threads_t()
    	{
    		PyEval_RestoreThread(m_thread_state);
    		m_thread_state = NULL;
    	}

	private:
    	PyThreadState * m_thread_state;
};



#endif /* GIL_HPP_ */
