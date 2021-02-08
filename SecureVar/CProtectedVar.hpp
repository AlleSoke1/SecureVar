#pragma once

extern unsigned char g_Keys[6];

template <class T>
class CProtectedVar
{
public:
	CProtectedVar(T Value)
		: m_MasterKey(1)
	{
		m_Value = _protect(Value);
	};

	__forceinline T _protect(T something)
	{
		T temp = something;
		unsigned char* buffer = (unsigned char*)&temp;
		//Alg 2
		for (int i = 1; i < sizeof(T); i++)
		{
			buffer[i] ^= buffer[i - 1] ^ (unsigned char)g_Keys[i % sizeof(g_Keys)];
			buffer[i] ^= m_MasterKey;
		}
		return temp;
	}

	__forceinline T _protect()
	{
		return _protect(m_Value);
	}

	__forceinline T _unprotect()
	{
		T temp = m_Value;
		unsigned char* buffer = (unsigned char*)&temp;
		//Alg 2
		for (int i = sizeof(T) - 1; i != 0; i--)
		{
			buffer[i] ^= buffer[i - 1] ^ (unsigned char)g_Keys[i % sizeof(g_Keys)];
			buffer[i] ^= m_MasterKey;
		}

		return temp;
	}

	__forceinline T get()
	{
		T Var = _unprotect();
		m_MasterKey = rand() % 255;
		m_Value = _protect(Var);
		return Var;
	}

	__forceinline T get_protected()
	{
		return m_Value;
	}

protected:
	T m_Value;
	BYTE m_MasterKey;
};
