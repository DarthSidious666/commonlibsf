#include "RE/B/BSLock.h"

namespace RE
{
	void BSNonReentrantSpinLock::Lock()
	{
		using func_t = decltype(&BSNonReentrantSpinLock::Lock);
		static REL::Relocation<func_t> func{ ID::BSNonReentrantSpinLock::Lock };
		return func(this);
	}

	bool BSNonReentrantSpinLock::TryLock()
	{
		return _InterlockedOr(reinterpret_cast<volatile long*>(&this->m_lock), 1) == 0;
	}

	void BSNonReentrantSpinLock::Unlock()
	{
		using func_t = int (*)(BSNonReentrantSpinLock*, std::int32_t, std::int8_t);
		static REL::Relocation<func_t> func{ ID::BSNonReentrantSpinLock::UnlockSubroutine };
		func(this, 1, 2);
	}

	void BSReadWriteLock::LockRead()
	{
		using func_t = decltype(&BSReadWriteLock::LockRead);
		static REL::Relocation<func_t> func{ ID::BSReadWriteLock::LockRead };
		return func(this);
	}

	void BSReadWriteLock::LockWrite()
	{
		using func_t = decltype(&BSReadWriteLock::LockWrite);
		static REL::Relocation<func_t> func{ ID::BSReadWriteLock::LockWrite };
		return func(this);
	}

	void BSReadWriteLock::UnlockRead()
	{
		using func_t = decltype(&BSReadWriteLock::UnlockRead);
		static REL::Relocation<func_t> func{ ID::BSReadWriteLock::UnlockRead };
		return func(this);
	}

	void BSReadWriteLock::UnlockWrite()
	{
		using func_t = decltype(&BSReadWriteLock::UnlockWrite);
		static REL::Relocation<func_t> func{ ID::BSReadWriteLock::UnlockWrite };
		return func(this);
	}

	void BSSpinLock::Lock()
	{
		using func_t = decltype(&BSSpinLock::Lock);
		static REL::Relocation<func_t> func{ ID::BSSpinLock::Lock };
		return func(this);
	}

	bool BSSpinLock::TryLock()
	{
		using func_t = decltype(&BSSpinLock::TryLock);
		static REL::Relocation<func_t> func{ ID::BSSpinLock::TryLock };
		return func(this);
	}

	void BSSpinLock::Unlock()
	{
		using func_t = decltype(&BSSpinLock::Unlock);
		static REL::Relocation<func_t> func{ ID::BSSpinLock::Unlock };
		return func(this);
	}
}
