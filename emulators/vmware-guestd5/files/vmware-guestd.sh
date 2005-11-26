#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: vmware-guestd
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD

PREFIX=%%PREFIX%%
. %%RC_SUBR%%

# Global
checkvm_cmd="${PREFIX}/sbin/vmware-checkvm > /dev/null"

# Functions
vmware_guest_vmmemctl_start()
{
	echo 'Loading vmmemctl kernel module.'
	kldload ${PREFIX}/lib/vmware-tools/modules/vmmemctl.ko >/dev/null 2>&1
}
vmware_guest_vmmemctl_start()
{
	echo 'Loading vmxnet kernel module.'
	kldload ${PREFIX}/lib/vmware-tools/modules/vmxnet.ko >/dev/null 2>&1
}

# VMware kernel module: vmmemctl
name="vmware_guest_vmmemctl"
rcvar=`set_rcvar`
start_precmd="${checkvm_cmd}"
start_cmd="vmware_guest_vmmemctl_start"
stop_precmd="${checkvm_cmd}"
stop_cmd=":"

load_rc_config $name
[ -z "$vmware_guest_vmmemctl_enable" ] && vmware_guest_vmmemctl_enable="NO"
[ -n "$vmware_guest_kmod_enable" ] && vmware_guest_vmmemctl_enable="$vmware_guest_kmod_enable"
run_rc_command "$1"

# VMware kernel module: vmxnet
name="vmware_guest_vmxnet"
rcvar=`set_rcvar`
start_precmd="${checkvm_cmd}"
start_cmd="vmware_guest_vmxnet_start"
stop_precmd="${checkvm_cmd}"
stop_cmd=":"

load_rc_config $name
[ -z "$vmware_guest_vmxnet_enable" ] && vmware_guest_vmxnet_enable="NO"
run_rc_command "$1"

# VMware guest daemon
name="vmware_guestd"
rcvar=`set_rcvar`
start_precmd="${checkvm_cmd}"
unset start_cmd
stop_precmd="${checkvm_cmd}"
unset stop_cmd
command="${PREFIX}/sbin/vmware-guestd"
command_args="--halt-command '/sbin/shutdown -p now' >/dev/null 2>&1"
pidfile="/var/run/${name}.pid"

load_rc_config $name
[ -z "$vmware_guestd_enable" ] && vmware_guestd_enable="YES"
[ -z "$vmware_guestd_flags" ] && vmware_guestd_flags="--background ${pidfile}"
run_rc_command "$1"
