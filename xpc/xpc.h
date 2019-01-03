#import "../Types.h"
#import "xpcTypes.h"

xpc_type_t xpc_get_type(xpc_object_t object);

xpc_connection_t xpc_connection_create(const char *name, dispatch_queue_t targetq);
xpc_connection_t xpc_connection_create_from_endpoint(xpc_endpoint_t endpoint);
xpc_connection_t xpc_connection_create_mach_service(const char *name, dispatch_queue_t targetq, uint64_t flags);
xpc_connection_t xpc_dictionary_get_remote_connection(xpc_object_t xdict);
xpc_connection_t xpc_array_create_connection(xpc_object_t xarray, size_t index);

xpc_object_t xpc_connection_send_message_with_reply_sync(xpc_connection_t connection, xpc_object_t message);
xpc_object_t xpc_connection_copy_entitlement_value(xpc_connection_t, const char* entitlement);
xpc_object_t xpc_dictionary_create(const char *const *keys, xpc_object_t const *values, size_t count);
xpc_object_t xpc_dictionary_create_reply(xpc_object_t original);
xpc_object_t xpc_dictionary_get_value(xpc_object_t xdict, const char *key);
xpc_object_t xpc_array_create(const xpc_object_t *objects, size_t count);
xpc_object_t xpc_array_get_value(xpc_object_t xarray, size_t index);
xpc_object_t xpc_fd_create(int fd);
xpc_object_t xpc_date_create(int64_t interval);
xpc_object_t xpc_copy_bootstrap(void);
xpc_object_t xpc_retain(xpc_object_t);

pid_t xpc_connection_get_pid(xpc_connection_t connection);

bool xpc_dictionary_apply(xpc_object_t xdict, xpc_dictionary_applier_t applier);
bool xpc_dictionary_get_bool(xpc_object_t xdict, const char *key);
bool xpc_array_apply(xpc_object_t xarray, xpc_array_applier_t applier);
bool xpc_array_get_bool(xpc_object_t xarray, size_t index);

double xpc_dictionary_get_double(xpc_object_t xdict, const char *key);
double xpc_array_get_double(xpc_object_t xarray, size_t index);

int64_t xpc_dictionary_get_date(xpc_object_t xdict, const char *key);
int64_t xpc_dictionary_get_int64(xpc_object_t xdict, const char *key);
int64_t xpc_array_get_date(xpc_object_t xarray, size_t index);
int64_t xpc_array_get_int64(xpc_object_t xarray, size_t index);
int64_t xpc_date_get_value(xpc_object_t xdate);

uint64_t xpc_dictionary_get_uint64(xpc_object_t xdict, const char *key);
uint64_t xpc_array_get_uint64(xpc_object_t xarray, size_t index);

size_t xpc_dictionary_get_count(xpc_object_t xdict);
size_t xpc_array_get_count(xpc_object_t xarray);

int xpc_dictionary_dup_fd(xpc_object_t xdict, const char *key);
int xpc_array_dup_fd(xpc_object_t xarray, size_t index);
int xpc_fd_dup(xpc_object_t xfd);

mach_port_t xpc_dictionary_copy_mach_send(xpc_object_t, const char *);

void xpc_release(xpc_object_t object);

void xpc_connection_resume(xpc_connection_t connection);
void xpc_connection_suspend(xpc_connection_t connection);
void xpc_connection_cancel(xpc_connection_t connection);
void xpc_connection_send_barrier(xpc_connection_t connection, dispatch_block_t barrier);
void xpc_connection_send_message(xpc_connection_t connection, xpc_object_t message);
void xpc_connection_send_message_with_reply(xpc_connection_t connection, xpc_object_t message, dispatch_queue_t replyq, xpc_handler_t handler);
void xpc_connection_set_context(xpc_connection_t connection, void *context);
void xpc_connection_set_event_handler(xpc_connection_t connection, xpc_handler_t handler);
void xpc_connection_set_target_queue(xpc_connection_t connection, dispatch_queue_t targetq);
void xpc_connection_set_bootstrap(xpc_connection_t, xpc_object_t bootstrap);
void xpc_connection_set_instance(xpc_connection_t, uuid_t);
void xpc_connection_set_oneshot_instance(xpc_connection_t, uuid_t instance);
void xpc_dictionary_set_mach_send(xpc_object_t, const char *, mach_port_t);
void xpc_connection_get_audit_token(xpc_connection_t, audit_token_t*);
void xpc_connection_kill(xpc_connection_t, int);

void xpc_array_append_value(xpc_object_t xarray, xpc_object_t value);
void xpc_array_set_double(xpc_object_t xarray, size_t index, double value);
void xpc_array_set_int64(xpc_object_t xarray, size_t index, int64_t value);
void xpc_array_set_uint64(xpc_object_t xarray, size_t index, uint64_t value);
void xpc_array_set_uuid(xpc_object_t xarray, size_t index, const uuid_t uuid);
void xpc_array_set_fd(xpc_object_t xarray, size_t index, int fd);
void xpc_array_set_string(xpc_object_t xarray, size_t index, const char *string);
void xpc_array_set_data(xpc_object_t xarray, size_t index, const void *bytes, size_t length);
void xpc_array_set_date(xpc_object_t xarray, size_t index, int64_t value);
void xpc_array_set_value(xpc_object_t xarray, size_t index, xpc_object_t value);

void xpc_dictionary_set_uuid(xpc_object_t xdict, const char *key, const uuid_t uuid);
void xpc_dictionary_set_connection(xpc_object_t xdict, const char *key,	xpc_connection_t connection);
void xpc_dictionary_set_bool(xpc_object_t xdict, const char *key, bool value);
void xpc_dictionary_set_double(xpc_object_t xdict, const char *key, double value);
void xpc_dictionary_set_string(xpc_object_t xdict, const char *key, const char *string);
void xpc_dictionary_set_int64(xpc_object_t xdict, const char *key, int64_t value);
void xpc_dictionary_set_uint64(xpc_object_t xdict, const char *key, uint64_t value);
void xpc_dictionary_set_date(xpc_object_t xdict, const char *key, int64_t value);
void xpc_dictionary_set_value(xpc_object_t xdict, const char *key, xpc_object_t value);
void xpc_dictionary_set_fd(xpc_object_t xdict, const char *key, int fd);

void xpc_transaction_begin(void);
void xpc_transaction_end(void);
void xpc_transaction_exit_clean(void);
void xpc_track_activity(void);

const void *xpc_array_get_data(xpc_object_t xarray, size_t index, size_t *length);
void *xpc_connection_get_context(xpc_connection_t connection);

const char *xpc_connection_get_name(xpc_connection_t connection);
const char *xpc_dictionary_get_string(xpc_object_t xdict, const char *key);
const char *xpc_array_get_string(xpc_object_t xarray, size_t index);
const char *xpc_string_get_string_ptr(xpc_object_t);