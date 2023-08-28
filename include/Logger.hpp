/**********************************************************************************************************************
 * Bukhtagram                                                                                                         *
 *                                                                                                                    *
 * Author: Bukhta Mykyta                                                                                              *
 *                                                                                                                    *
 * Copyright ©2023 Bukhta Mykyta                                                                                      *
 *                                                                                                                    *
 * This software is distributed under the following license:                                                          *
 *                                                                                                                    *
 * 1. This code may not be modified, redistributed, or used to create derivative works.                               *
 * 2. Any use of this code for commercial purposes is prohibited without prior written permission of the author.      *
 * 3. The author is not liable for any damages caused by the use of this software.                                    *
 * 4. Copies of this license or references to it must be included in all copies or significant parts of the software. *
 *                                                                                                                    *
 * For permission for commercial use, contact the author at the following address: nikita.bukhta.dev@gmail.com.       *
 **********************************************************************************************************************                                                                                                                    *
 */

#ifndef LOGGER_LOGGER_HPP
#define LOGGER_LOGGER_HPP

#include <boost/core/demangle.hpp>
#include <boost/current_function.hpp>
#include <boost/log/trivial.hpp>

#include <string>

std::string get_func_name(const std::string &func_info);
std::string get_class_name(const std::string &class_info);

#define __CLASS_NAME__ std::string("[") + get_class_name(boost::core::demangle(typeid(*this).name())) + "]"
#define __FUNCTION_NAME__ std::string("[") + get_func_name(BOOST_CURRENT_FUNCTION) + "]"
#define DECLARE_TAG_SCOPE std::string logger_function_info = __CLASS_NAME__ + " " + __FUNCTION_NAME__;

#define LOG_TRACE BOOST_LOG_TRIVIAL(trace) << logger_function_info << '\t'
#define LOG_DEBUG BOOST_LOG_TRIVIAL(debug) << logger_function_info << '\t'
#define LOG_INFO BOOST_LOG_TRIVIAL(info) << logger_function_info << '\t'
#define LOG_WARNING BOOST_LOG_TRIVIAL(warning) << logger_function_info << '\t'
#define LOG_ERROR BOOST_LOG_TRIVIAL(error) << logger_function_info << '\t'
#define LOG_FATAL BOOST_LOG_TRIVIAL(fatal) << logger_function_info << '\t'

#endif  // !LOGGER_LOGGER_HPP;