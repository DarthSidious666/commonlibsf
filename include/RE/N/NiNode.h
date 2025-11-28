#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiAVObject.h"
#include "RE/N/NiTransform.h"

#include <cstdint>
#include <cstddef>
#include <vector>
#include <type_traits>

namespace RE
{
    class NiAVObject;                            // base for renderable objects
    class NiRefObject;                           // ref-counted base
    class NiObject;                              // intermediate base
    class NiObjectNET;                           // intermediate base
    struct NiTransform;                          // position/rotation/scale block
    class BSFixedString;                         // engine fixed-string wrapper
    template <class K, class V> class BSTHashMap;

    class NiNode : public NiAVObject
    {
        public:
            // Virtual destructor / vtable are present (attributes = 0x40 in RTTI).
            virtual ~NiNode();

            // Utility / accessors (typical of prior NiNode implementations)
            virtual NiNode*       GetAsNiNode();                       // return this typed pointer
            virtual void          AddChild(NiAVObject* child);       // attach child
            virtual bool          RemoveChild(NiAVObject* child);    // detach child
            virtual NiAVObject*   GetObjectByName(const BSFixedString& name);
            virtual NiAVObject*   FindObjectRecursive(const BSFixedString& name); // recursive search

            // Transform accessors (CE2 likely uses NiTransform or similar)
            virtual NiTransform*  GetLocalTransform();
            virtual void          SetLocalTransform(const NiTransform& t);

        public:
      
            BSTArray<NiPointer<NiAVObject>> children;       // dynamic list of child pointers

            // Optional extra per-node metadata (CE2 often adds an "extraData" pointer or structure)
            void* extraData;                                // pointer to NodeExtra/metadata (inferred)

            // Transform (local)
            NiTransform localTransform;                      // position/rotation/scale for this node

            // Flags, LOD, visibility, or other engine-specific fields
            std::uint32_t flags;                             // generic flags
            std::uint32_t pad;                               // padding / reserved


    };

    static_assert(sizeof(NiNode) == 0x40);
}