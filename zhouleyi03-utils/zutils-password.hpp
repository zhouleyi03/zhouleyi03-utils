#pragma once
#pragma once
#include <string>

namespace zutils
{
	namespace password
	{
		/*

			-����޸��� 2019/7/1
			˵������ָ���ı�ʹ��vigenere���뷽ʽ���ܡ�

		*/
		std::string vigenerePasswordEncrypt(const std::string& text_to_encrypt, const std::string& key)
		{
			int ch_text = 0;
			int ch_key = 0;
			int buffer = 0;
			int res = 0;
			std::size_t index = 0;
			std::string password_container;

			for (const auto& ch : text_to_encrypt)
			{
				ch_text = static_cast<int>(ch);
				ch_key = static_cast<int>(key[index]);
				buffer = (ch_text & 32);
				ch_key -= (ch_key & 32);
				ch_text -= buffer;
				res = ch_text + ch_key - 129;
				if (res > 26)
					res -= 26;
				password_container.push_back(static_cast<char>(res + 64 + buffer));
				if (index == key.size() - 1)
					index = 0;
				else
					++index;
			}
			return password_container;
		}

		/*

			-����޸��� 2019/7/1
			˵������ָ���ı�ʹ��vigenere���뷽ʽ���ܡ�

		*/
		std::string vigenerePasswordDecrypt(const std::string& text_to_decrypt, const std::string& key)
		{
			int ch_pw = 0;
			int ch_key = 0;
			int buffer = 0;
			int res = 0;
			std::size_t index = 0;
			std::string decrypted_text;

			for (const auto& ch : text_to_decrypt)
			{
				ch_pw = static_cast<int>(ch);
				ch_key = static_cast<int>(key[index]);
				buffer = (ch_pw & 32);
				ch_key -= (ch_key & 32);
				ch_pw -= buffer;

				res = ch_pw - ch_key + 1;
				if (res < 1)
					res += 26;
				decrypted_text.push_back(static_cast<char>(res + 64 + buffer));

				if (index == key.size() - 1)
					index = 0;
				else
					++index;
			}
			return decrypted_text;
		}
	}
}