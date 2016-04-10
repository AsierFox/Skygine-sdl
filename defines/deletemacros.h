#ifndef _DELETE_MACROS_H_
#define _DELETE_MACROS_H_

/**
* Macro for deleting objects.
*/
#define SAFE_DELETE(x) { if (x) { delete x; x = nullptr; } }

/**
 * Macro for releasing COM objects.
 */
#define SAFE_RELEASE(x) { if (x) { x->release(); x = nullptr; } }

#endif // _DELETE_MACROS_H_
