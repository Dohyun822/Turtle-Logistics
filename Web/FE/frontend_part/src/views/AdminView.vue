<template>
  <div id="adminMainContainer" :style="{ height: appHeight + 'px' }">
    <sidebar-nav></sidebar-nav>
    <div class="adminSubContainer">
      <header-nav></header-nav>
      <router-view />
    </div>
    <video class="VideoContainer" ref="videoElement" hidden autoplay></video>
    <canvas ref="canvasElement" hidden></canvas>
  </div>
  <public-modal
    :isVisible="isModalVisible"
    :title="modalTitle"
    :message="modalMessage"
    @close="isModalVisible = false"
  />
</template>

<script>
import HeaderNav from "@/components/common/HeaderNav.vue";
import SidebarNav from "@/components/common/SidebarNav.vue";
// import AdminMainView from "@/components/Admin/AdminMainView.vue";
import { mapState } from "vuex";
import PublicModal from "@/components/Modals/PublicModal.vue";

export default {
  name: "AdminView",
  data: () => ({
    appHeight: 900,
    myTimer: null,
    screenshot: null,
    isModalVisible: false,
    modalTitle: "Alert",
    modalMessage: "",
  }),
  created() {
    this.changeImg("0000");
  },
  methods: {
    // updateAppHeight(childContentHeight) {
    //   // 자식 컴포넌트의 내용 높이에 따라 App.vue의 높이를 동적으로 변경
    //   if (childContentHeight > 800) {
    //     this.appHeight = childContentHeight + 200;
    //   } else {
    //     this.appHeight = 1200;
    //   }
    // },
    sendMessage(log_num) {
      this.$store.dispatch("admin/SendSMS", log_num);
    },
    changeImg(machine_id) {
      this.$store.state.errorImg = `/Error_BluePrint/BluePrint_${machine_id}.png`;
    },
    async getMachineStatus() {
      await this.$store.dispatch("machine/getMachineStatus");
    },
    async initWebcam() {
      try {
        const devices = await navigator.mediaDevices.enumerateDevices();
        const notebookCamera = devices.find(
          (device) => device.kind === "videoinput" && device.label.includes("Web Camera")
        );
        if (notebookCamera) {
          const notebookStream = await navigator.mediaDevices.getUserMedia({
            video: { deviceId: notebookCamera.deviceId },
          });
          notebookStream; // 노트북 카메라 비디오 요소
        } else {
          console.error("Notebook camera not found.");
        }
        const webcamStream = await navigator.mediaDevices.getUserMedia({
          video: true,
        });
        this.$refs.videoElement.srcObject = webcamStream; // 웹캠 비디오 요소
      } catch (error) {
        console.error("Error accessing webcam:", error);
      }
    },
    takeScreenshot(log_num) {
      const videoElement = this.$refs.videoElement;
      const canvasElement = this.$refs.canvasElement;

      // Set canvas dimensions to match the video dimensions
      canvasElement.width = videoElement.videoWidth;
      canvasElement.height = videoElement.videoHeight;

      // Draw the video frame onto the canvas
      const ctx = canvasElement.getContext("2d");
      ctx.drawImage(videoElement, 0, 0, videoElement.videoWidth, videoElement.videoHeight);

      // Get the data URL of the canvas content (base64 encoded image)
      const dataURL = canvasElement.toDataURL("image/png");

      // Convert the dataURL to an image File
      const fetchImage = async (url) => {
        const response = await fetch(url);
        const blob = await response.blob();
        return new File([blob], log_num + ".png", { type: "image/png" });
      };

      // Set the screenshot in the data property to display it on the page
      this.screenshot = dataURL;

      fetchImage(dataURL).then((imageFile) => {
        this.$store.dispatch("admin/takeScreenshot", {
          image: imageFile,
          log_num: log_num,
        });
      });
    },
  },
  components: {
    HeaderNav,
    SidebarNav,
    PublicModal,
  },
  async mounted() {
    await this.initWebcam();
    await this.getMachineStatus();
    this.myTimer = setInterval(async () => {
      await this.getMachineStatus(); // 매 초마다 새 데이터를 가져옵니다.
      let addedLogs;
      // previousMachineLog와 machineLog를 비교하여 새로운 로그를 찾습니다.
      if (this.machineStatus[`로그`] != null && this.machineStatus[`로그`].length > 0) {
        const brokenList = this.machineStatus[`로그`];
        this.changeImg(brokenList[0].machine_id);
        addedLogs = this.machineStatus["로그"].filter((log) => !log.recorded);

        // addedLogs가 비어있지 않으면, 새로운 로그가 추가되었음을 의미합니다.
        if (addedLogs.length > 0) {
          for (let log of addedLogs) {
            // 이미지전송
            this.takeScreenshot(log.log_num);
            // 새로운 로그에 대해 원하는 동작을 수행합니다.
            this.modalTitle = "Warning";
            this.modalMessage = `${log.machine_id} 공정에 이상이 발생했습니다. <br>확인 후 메뉴얼에 따라 조치해주시기 바랍니다.`;
            this.isModalVisible = true;
            this.sendMessage(log.log_num);
          }
        }
      } else {
        this.changeImg("0000");
      }
    }, 1000);
  },
  computed: {
    ...mapState("machine", ["machineStatus"]),
    ...mapState(["errorImg"]),
  },
};
</script>

<style scoped>
#adminMainContainer {
  min-height: 100vh; /* 뷰포트 높이의 100% */
  display: flex;
  width: 100%;
  height: auto;
}

.adminSubContainer {
  flex-direction: column;
  width: 100%;
  height: 100vh;
}

.VideoContainer {
  width: 450px;
}
</style>
