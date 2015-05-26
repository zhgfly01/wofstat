/* Generated by GOB (v2.0.11)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef __GNOME_PILOT_CONDUIT_FILE_H__
#define __GNOME_PILOT_CONDUIT_FILE_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gnome.h>
#include "gnome-pilot-conduit.h"
#include "gnome-pilot-dbinfo.h"


/*
 * Type checking and casting macros
 */
#define GNOME_TYPE_PILOT_CONDUIT_FILE	(gnome_pilot_conduit_file_get_type())
#define GNOME_PILOT_CONDUIT_FILE(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), gnome_pilot_conduit_file_get_type(), GnomePilotConduitFile)
#define GNOME_PILOT_CONDUIT_FILE_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), gnome_pilot_conduit_file_get_type(), GnomePilotConduitFile const)
#define GNOME_PILOT_CONDUIT_FILE_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), gnome_pilot_conduit_file_get_type(), GnomePilotConduitFileClass)
#define GNOME_IS_PILOT_CONDUIT_FILE(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), gnome_pilot_conduit_file_get_type ())

#define GNOME_PILOT_CONDUIT_FILE_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), gnome_pilot_conduit_file_get_type(), GnomePilotConduitFileClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_GNOME_PILOT_CONDUIT_FILE__
#define __TYPEDEF_GNOME_PILOT_CONDUIT_FILE__
typedef struct _GnomePilotConduitFile GnomePilotConduitFile;
#endif
struct _GnomePilotConduitFile {
	GnomePilotConduit __parent__;
};

/*
 * Class definition
 */
typedef struct _GnomePilotConduitFileClass GnomePilotConduitFileClass;
struct _GnomePilotConduitFileClass {
	GnomePilotConduitClass __parent__;
	/*signal*/int (* install_db) (GnomePilotConduitFile * self, int pisock, gchar * src_file, gboolean rm);
};


/*
 * Public methods
 */
GType	gnome_pilot_conduit_file_get_type	(void);
GtkObject * 	gnome_pilot_conduit_file_new	(GPilotPilot * pilot);
int 	gnome_pilot_conduit_file_install_db	(GnomePilotConduitFile * self,
					int pisock,
					gchar * src_file,
					gboolean rm);

/*
 * Signal connection wrapper macros
 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define gnome_pilot_conduit_file_connect__install_db(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT_FILE(__extension__ ({GnomePilotConduitFile *___object = (object); ___object; })),"install_db",(GCallback) __extension__ ({int (* ___install_db) (GnomePilotConduitFile * ___fake___self, int ___fake___pisock, gchar * ___fake___src_file, gboolean ___fake___rm, gpointer ___data ) = (func); ___install_db; }), (data))
#define gnome_pilot_conduit_file_connect_after__install_db(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT_FILE(__extension__ ({GnomePilotConduitFile *___object = (object); ___object; })),"install_db",(GCallback) __extension__ ({int (* ___install_db) (GnomePilotConduitFile * ___fake___self, int ___fake___pisock, gchar * ___fake___src_file, gboolean ___fake___rm, gpointer ___data ) = (func); ___install_db; }), (data))
#define gnome_pilot_conduit_file_connect_data__install_db(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT_FILE(__extension__ ({GnomePilotConduitFile *___object = (object); ___object; })),"install_db",(GCallback) __extension__ ({int (* ___install_db) (GnomePilotConduitFile * ___fake___self, int ___fake___pisock, gchar * ___fake___src_file, gboolean ___fake___rm, gpointer ___data ) = (func); ___install_db; }), (data), (destroy_data), (GConnectFlags)(flags))
#else /* __GNUC__ && !__STRICT_ANSI__ */
#define gnome_pilot_conduit_file_connect__install_db(object,func,data)	g_signal_connect(GNOME_PILOT_CONDUIT_FILE(object),"install_db",(GCallback)(func),(data))
#define gnome_pilot_conduit_file_connect_after__install_db(object,func,data)	g_signal_connect_after(GNOME_PILOT_CONDUIT_FILE(object),"install_db",(GCallback)(func),(data))
#define gnome_pilot_conduit_file_connect_data__install_db(object,func,data,destroy_data,flags)	g_signal_connect_data(GNOME_PILOT_CONDUIT_FILE(object),"install_db",(GCallback)(func),(data),(destroy_data),(GConnectFlags)(flags))
#endif /* __GNUC__ && !__STRICT_ANSI__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
