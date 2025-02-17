FROM rockylinux:8.5 AS base

ARG REPO_NAME=c-play
ARG USERNAME=play
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN set -eux -o pipefail && \
    dnf install -y nss-tools openssl ca-certificates && \
    dnf install -y curl dnf-utils dnf-plugins-core epel-release findutils git git-lfs iproute jq ncurses rsync sudo tree which zsh && \
    dnf config-manager --set-enabled powertools && \ 
    dnf install -y cmake gcc gcc-c++ glib2-devel procps-ng rpm-build 

FROM base AS user

# Create the user
RUN groupadd --gid ${USER_GID} ${USERNAME} && \
  useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} -s /bin/zsh && \
  echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} && \
  chmod 0440 /etc/sudoers.d/${USERNAME}

########### NON ROOT FROM HERE DOWN ###########
USER ${USERNAME}

RUN set -eux && \
    mkdir -p ${HOME}/bin && \
    mkdir -p ${HOME}/go/bin && \
    sudo mkdir -p /workdir/${REPO_NAME} && \
    sudo chown ${USERNAME}:${USERNAME} /workdir

# envs
ENV HOME="/home/${USERNAME}"
ENV SDK_HOME=${HOME}/sdk
ENV PATH=${HOME}/bin:${PATH}

# pretty bash
COPY --chown=${USERNAME}:${USERNAME} .bash_pretty ${HOME}/.bash_pretty
RUN set -eux && \
    echo "source ${HOME}/.bash_pretty" >> ${HOME}/.bashrc


