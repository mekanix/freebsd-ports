// vim: syntax=groovy
pipeline {
    agent { label 'poudriere' }

    environment {
        DISTDIR = "/usr/local-distfiles"
        PNAME = "jenkins-main"
    }
    parameters {
        string(description: 'Dev package to build', name: 'devPackage', defaultValue: '')
    }
    stages {
        stage('Prepare env') {
            steps {
                echo "PWD is ${PWD} and port name is ${PNAME}"
                // Register this workspace in Poudriere, if it isn't there
                // already
                sh 'poudriere ports -lq | grep -q " ${PWD}$" || sudo poudriere ports -c -m null -M "${PWD}" -p "${PNAME}"'
            }
        }
        stage('Build prod packages') {
            when {
                expression { !buildDevPackage() }
            }
            environment {
                // Build all of the packages we care about.  Unfortunately
                // there's no easy way to automatically determine that.  Here
                // are two methods:
                //
                // The first method undercounts packages because it doesn't
                // consider stuff specified in Salt, rather than Pillar
                // sudo salt -t10 -G 'kernel:FreeBSD' pillar.get packages
                //
                // The second method overcounts packages because it includes
                // stuff that was installed by hand and forgotten about, as well
                // as stuff that has been removed from pillar
                // sudo salt -t 10 -G 'kernel:FreeBSD' cmd.run \
                //    'pkg query -e "%a = 0" %n'
                PORTSALL = ' \
                    axcient/add_mbr \
                    axcient/add_mbr-stg \
                    axcient/axcient-utils \
                    axcient/cloudserver \
                    axcient/cloudserver-stg \
                    axcient/cloudserver2 \
                    axcient/cloudserver2-stg \
                    axcient/dcpkg \
                    axcient/dcpkg-stg \
                    axcient/dralserver \
                    axcient/dralserver-stg \
                    axcient/efsserver \
                    axcient/efs-vm-utils \
                    axcient/filestore-clone \
                    axcient/py-malloc-exporter \
                    axcient/py-drive-exporter \
                    axcient/py-pxeweb \
                    axcient/migration-tools \
                    axcient/rsync-proxy \
                    axcient/rsync-proxy-stg \
                    axcient/smart-recovery \
                    axcient/smart-recovery-stg \
                    axcient/spxops-vmagent \
                    axcient/storage-cleanup \
                    axcient/szs \
                    axcient/szs-stg \
                    axcient/szs-migrator \
                    axcient/vdisk-fuse \
                    axcient/vm-migrator \
                    axcient/vt2 \
                    axcient/vt2-stg \
                    axcient/ztop-exporter \
                    benchmarks/fio \
                    benchmarks/flamegraph \
                    benchmarks/iozone \
                    benchmarks/iperf3 \
                    converters/unix2dos \
                    databases/pgbouncer \
                    databases/py-prometheus-pgbouncer-exporter \
                    databases/redis \
                    dns/dnsmasq \
                    devel/delve \
                    devel/gdb \
                    devel/git \
                    devel/hwloc2 \
                    devel/py-pip \
                    devel/py-tox \
                    devel/py-virtualenv \
                    devel/uclcmd \
                    devel/valgrind \
                    editors/nano \
                    editors/vim \
                    emulators/qemu@tools \
                    ftp/cap-ftpd \
                    graphics/py-pillow \
                    lang/expect \
                    lang/go121 \
                    lang/python3 \
                    mail/ssmtp \
                    mail/mutt \
                    misc/mbuffer \
                    misc/mc \
                    net/bmon \
                    net/ipxe \
                    net/cloud-init \
                    net/mtr-nox11 \
                    net-mgmt/geom-exporter \
                    net-mgmt/grok_exporter \
                    net-mgmt/iftop \
                    net-mgmt/lldpd \
                    net-mgmt/nfs-exporter \
                    net-mgmt/unbound_exporter \
                    net-mgmt/pktstat \
                    net-mgmt/py-network-interface-exporter \
                    net-mgmt/py-zfs-exporter \
                    net-mgmt/py-ses-exporter \
                    net-mgmt/py-smartctl-exporter \
                    net-mgmt/telegraf \
                    net-mgmt/zabbix5-agent \
                    net/nss-pam-ldapd \
                    net/nss_ldap \
                    net/rsync \
                    net/wireshark \
                    ports-mgmt/modules2tuple \
                    ports-mgmt/portlint \
                    security/gnupg \
                    security/nmap \
                    security/pam_mkhomedir \
                    security/py-asyncssh \
                    security/sudo \
                    security/wazuh-agent \
                    shells/bash \
                    shells/ksh93 \
                    sysutils/beats7 \
                    sysutils/beats8 \
                    sysutils/dmidecode \
                    sysutils/dtrace-toolkit \
                    sysutils/fusefs-ntfs \
                    sysutils/gstat-rs \
                    sysutils/intel-nvmupdate-100g \
                    sysutils/iocage \
                    sysutils/ipmitool \
                    sysutils/jail_exporter \
                    sysutils/mcelog \
                    sysutils/node_exporter \
                    sysutils/pv \
                    sysutils/py-salt \
                    sysutils/rsyslog8 \
                    sysutils/sas2flash \
                    sysutils/sas3flash \
                    sysutils/sas3ircu \
                    sysutils/storcli \
                    sysutils/screen \
                    sysutils/sg3_utils \
                    sysutils/smartmontools \
                    sysutils/smp_utils \
                    sysutils/tmux \
                    sysutils/zfs-stats-lite \
                    sysutils/zfsnap2 \
                    sysutils/zrepl \
                    sysutils/ztop \
                    textproc/jq \
                    textproc/py-elasticsearch \
                    textproc/ripgrep \
                    www/py-aiohttp \
                    www/uwsgi \
                    '
                PORTS13 = ' \
                    devel/ncurses \
                    '
                PORTS14 = ' \
                    java/openjdk11 \
                    math/py-pandas \
                    ports-mgmt/poudriere \
                    www/nginx \
                    '
                // Ports that need to be rebuilt for every minor version of the
                // OS, not just major versions.
                PORTSMINOR = 'devel/py-libzfs'
            }
            steps {
                echo "Building prod packages"

                // Fetch all of our proprietary ports.  Poudriere can't do it
                // because it lacks Jenkins' ssh key.
                sh 'cd axcient/axcient-utils; make fetch'
                sh 'cd axcient/efsserver; make fetch'
                sh 'cd axcient/efs-vm-utils; make fetch'
                sh 'cd axcient/add_mbr; make fetch'
                sh 'cd axcient/add_mbr-stg; make fetch'
                sh 'cd axcient/cloudserver; make fetch'
                sh 'cd axcient/cloudserver-stg; make fetch'
                sh 'cd axcient/cloudserver2; make fetch'
                sh 'cd axcient/cloudserver2-stg; make fetch'
                sh 'cd axcient/dcpkg; make fetch'
                sh 'cd axcient/dcpkg-stg; make fetch'
                sh 'cd axcient/dralserver; make fetch'
                sh 'cd axcient/dralserver-stg; make fetch'
                sh 'cd axcient/py-axcient-helpers; make fetch'
                sh 'cd axcient/py-drive-exporter; make fetch'
                sh 'cd axcient/py-malloc-exporter; make fetch'
                sh 'cd axcient/py-pxeweb; make fetch'
                sh 'cd net-mgmt/py-ses-exporter; make fetch'
                sh 'cd axcient/filestore-clone; make fetch'
                sh 'cd axcient/migration-tools; make fetch'
                sh 'cd axcient/rsync-proxy; make fetch'
                sh 'cd axcient/rsync-proxy-stg; make fetch'
                sh 'cd axcient/smart-recovery; make fetch'
                sh 'cd axcient/smart-recovery-stg; make fetch'
                sh 'cd axcient/spxops-vmagent; make fetch'
                sh 'cd axcient/storage-cleanup; make fetch'
                sh 'cd axcient/szs; make fetch'
                sh 'cd axcient/szs-stg; make fetch'
                sh 'cd axcient/szs-migrator; make fetch'
                sh 'cd axcient/vdisk-fuse; make fetch'
                sh 'cd axcient/vdisk-fuse-stg; make fetch'
                sh 'cd axcient/vm-migrator; make fetch'
                sh 'cd axcient/vt2; make fetch'
                sh 'cd axcient/vt2-stg; make fetch'
                sh 'cd axcient/ztop-exporter; make fetch'
                sh 'cd ftp/cap-ftpd; make fetch'
                sh 'cd net-mgmt/py-network-interface-exporter; make fetch'
                sh 'cd net-mgmt/py-smartctl-exporter; make fetch'
                sh 'cd net-mgmt/py-zfs-exporter; make fetch'

                sh 'sudo poudriere bulk -j 14_0-AXCIENT1_amd64 -p "${PNAME}" \
                    ${PORTSALL} ${PORTS14}'
                sh 'sudo poudriere bulk -j 13_2-AXCIENT1_amd64 -p "${PNAME}" \
                    ${PORTSALL} ${PORTS13}'
                sh 'sudo poudriere bulk -j 13_2-AXCIENT1_amd64 -p "${PNAME}" \
                    ${PORTSMINOR} '
            }
        }
        stage('Build dev package') {
            when {
                expression { buildDevPackage() }
            }
            steps {
                echo "Building ${env.devPackage} package"

                // Fetch all of our proprietary dev ports.  Poudriere can't do it
                // because it lacks Jenkins' ssh key.
                sh 'cd axcient/add_mbr-dev; make fetch'
                sh 'cd axcient/cloudserver2-dev; make fetch'
                sh 'cd axcient/dralserver-dev; make fetch'
                sh 'cd axcient/grpc-tests-dev; make fetch'
                sh 'cd axcient/smart-recovery-dev; make fetch'
                sh 'cd axcient/vdisk-fuse-dev; make fetch'
                sh 'cd axcient/szs-dev; make fetch'
                sh 'cd axcient/vt2-dev; make fetch'
                sh 'cd axcient/rsync-proxy-dev; make fetch'

                sh "sudo poudriere bulk -j 14_0-AXCIENT1_amd64 -p ${PNAME} axcient/${env.devPackage}"
                sh "sudo poudriere bulk -j 13_2-AXCIENT1_amd64 -p ${PNAME} axcient/${env.devPackage}"
            }
            post {
                failure {
                    slackSend(
                        channel: "#freebsd-ports-dev-failures", 
                        color: 'danger', 
                        message: "freebsd-ports dev package build failed \n\nPort: ${env.devPackage} \nJob: ${env.JOB_NAME} \nBuild Number: ${env.BUILD_NUMBER} \nbuild URL: ${env.BUILD_URL}",
                        tokenCredentialId: 'RBQASlackToken'
                    )
                }
            }
        }
    }
    post {
        failure {
            mail body: "freebsd-ports: ${env.JOB_NAME} <br>Build Number: ${env.BUILD_NUMBER} <br> build URL: ${env.BUILD_URL}", charset: 'UTF-8', mimeType: 'text/html', subject: "ERROR CI: FreeBSD Ports -> ${env.JOB_NAME}", to: "storageteam@axcient.com";
        }
    }
}

def buildDevPackage() {
    return params.devPackage != ""
}
