#ifndef RS_TLV_GENERIC_MAP_H
#define RS_TLV_GENERIC_MAP_H

/*
 * libretroshare/src/serialiser: rstlvgenericmap.h
 *
 * RetroShare Serialiser.
 *
 * Copyright 2014 by Robert Fernie
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License Version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA.
 *
 * Please report all bugs and problems to "retroshare@lunamutt.com".
 *
 */

#include "serialiser/rstlvitem.h"
#include "serialiser/rstlvgenericparam.h"

#if 0
#include <map>

#include <stdlib.h>
#include <stdint.h>

#endif

/*********************************** RsTlvGenericPairRef ***********************************/

template<class K, class V>
class RsTlvGenericPairRef: public RsTlvItem
{
	public:
	 RsTlvGenericPairRef(uint16_t pair_type, 
		uint16_t key_type, uint16_t value_type, K &k, V &v)
	:mPairType(pair_type), mKeyType(key_type), 
	 mValueType(value_type), mKey(k), mValue(v)  { return; }

virtual ~RsTlvGenericPairRef() { return; }
virtual uint32_t TlvSize() const;
virtual void	 TlvClear();
virtual bool     SetTlv(void *data, uint32_t size, uint32_t *offset) const; 
virtual bool     GetTlv(void *data, uint32_t size, uint32_t *offset); 
virtual std::ostream &print(std::ostream &out, uint16_t indent) const;

	uint16_t mPairType;
	uint16_t mKeyType;
	uint16_t mValueType;
	K &mKey;
	V &mValue;
};


/************************************ RsTlvGenericMapRef ***********************************/

template<class K, class V>
class RsTlvGenericMapRef: public RsTlvItem
{
	public:
	 RsTlvGenericMapRef(uint16_t map_type, uint16_t pair_type, 
		uint16_t key_type, uint16_t value_type, std::map<K, V> &refmap)
	:mMapType(map_type), mPairType(pair_type), 
	 mKeyType(key_type), mValueType(value_type), mRefMap(refmap)  { return; }

virtual ~RsTlvGenericMapRef() { return; }
virtual uint32_t TlvSize() const;
virtual void	 TlvClear();
virtual bool     SetTlv(void *data, uint32_t size, uint32_t *offset) const; 
virtual bool     GetTlv(void *data, uint32_t size, uint32_t *offset); 
virtual std::ostream &print(std::ostream &out, uint16_t indent) const;

	uint16_t mMapType;
	uint16_t mPairType;
	uint16_t mKeyType;
	uint16_t mValueType;
	std::map<K, V> &mRefMap;
};


#include "rstlvgenericmap.inl"

#endif

